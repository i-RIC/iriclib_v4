#include "error_macros.h"
#include "iriclib_cc.h"
#include "iriclib_errorcodes.h"
#include "h5cgnsbase.h"
#include "h5cgnsconditiongroup.h"
#include "h5cgnsfile.h"

#include "internal/iric_h5cgnsfiles.h"
#include "internal/iric_logger.h"

using namespace iRICLib;

int cg_iRIC_Read_Integer(int fid, const char* name, int* value)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;

	ier = file->ccBase()->ccGroup()->readIntegerValue(name, value);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Read_Real(int fid, const char* name, double* value)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;

	ier = file->ccBase()->ccGroup()->readRealValueAsDouble(name, value);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Read_RealSingle(int fid, const char* name, float* value)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;

	ier = file->ccBase()->ccGroup()->readRealValueAsFloat(name, value);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Read_StringLen(int fid, const char* name, int* length)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;

	ier = file->ccBase()->ccGroup()->readStringLen(name, length);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Read_String(int fid, const char* name, char* strvalue)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;
	ier = file->ccBase()->ccGroup()->readString(name, strvalue);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Read_FunctionalSize(int fid, const char* name, int* size)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;

	ier = file->ccBase()->ccGroup()->readFunctionalSize(name, size);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Read_Functional(int fid, const char* name, double* x_arr, double* y_arr)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;

	ier = file->ccBase()->ccGroup()->readFunctional(name, x_arr, y_arr);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Read_FunctionalWithName(int fid, const char* name, const char* paramname, double* v_arr)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;

	ier = file->ccBase()->ccGroup()->readFunctionalWithName(name, paramname, v_arr);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Read_Functional_RealSingle(int fid, const char* name, float* x_arr, float* y_arr)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;
	ier = file->ccBase()->ccGroup()->readFunctional(name, x_arr, y_arr);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Read_FunctionalWithName_RealSingle(int fid, const char* name, const char* paramname, float* v_arr)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;
	ier = file->ccBase()->ccGroup()->readFunctionalWithName(name, paramname, v_arr);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Read_FunctionalWithName_String(int fid, const char* name, const char* paramname, char* strvalue)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;
	ier = file->ccBase()->ccGroup()->readFunctionalWithNameString(name, paramname, strvalue);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Read_FunctionalWithName_StringLen(int fid, const char* name, const char* paramname, int* length)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;

	ier = file->ccBase()->ccGroup()->readFunctionalWithNameStringLen(name, paramname, length);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Write_Integer(int fid, const char* name, int value)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;

	ier = file->ccBase()->ccGroup()->writeIntegerValue(name, value);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Write_Real(int fid, const char* name, double value)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;

	ier = file->ccBase()->ccGroup()->writeRealValue(name, value);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Write_String(int fid, const char* name, const char* value)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;

	ier = file->ccBase()->ccGroup()->writeString(name, value);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Write_Functional(int fid, const char* name, int length, double* x_arr, double* y_arr)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;

	ier = file->ccBase()->ccGroup()->writeFunctional(name, length, x_arr, y_arr);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Write_FunctionalWithName(int fid, const char* name, const char* paramname, int length, double* v_arr)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;

	ier = file->ccBase()->ccGroup()->writeFunctionalWithName(name, paramname, length, v_arr);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}

int cg_iRIC_Write_FunctionalWithName_String(int fid, const char* name, const char* paramname, const char* value)
{
	_IRIC_LOGGER_TRACE_ENTER();

	H5CgnsFile* file;
	int ier = _iric_h5cgnsfiles_get(fid, &file);
	RETURN_IF_ERR;

	ier = file->ccBase()->ccGroup()->writeFunctionalWithNameString(name, paramname, value);
	RETURN_IF_ERR;

	_IRIC_LOGGER_TRACE_LEAVE();
	return IRIC_NO_ERROR;
}
