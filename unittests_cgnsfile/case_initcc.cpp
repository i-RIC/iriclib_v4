#include "macros.h"

#if defined(HAVE_QT)
#include <QFile>
#else
#include "fs_copy.h"
#endif

#include <cgnslib.h>
#include <iriclib.h>

#include <iostream>

extern "C" {

void case_InitCC()
{
	remove("case_initcc.cgn");
#if defined(HAVE_QT)
	QFile::copy("case_nogrid.cgn", "case_initcc.cgn");
#else
	fs::copy("case_nogrid.cgn", "case_initcc.cgn");
#endif

	int fid;
	int ier = cg_open("case_nogrid.cgn", CG_MODE_MODIFY, &fid);

	VERIFY_LOG("cg_open() ier == 0", ier == 0);
	VERIFY_LOG("cg_open() fid != 0", fid != 0);

	ier = cg_iRIC_Init(fid);

	VERIFY_LOG("cg_iRIC_Init() ier == 1", ier == 1);

	ier = cg_iRIC_GotoCC(fid);

	VERIFY_LOG("cg_iRIC_GotoCC() ier == 0", ier == 0);

	cg_close(fid);

	remove("case_initcc.cgn");
}

} // extern "C"
