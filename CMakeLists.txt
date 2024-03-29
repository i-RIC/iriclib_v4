cmake_minimum_required(VERSION 3.14) # SWIG_MODULE_NAME

# SWIG: use SWIG_MODULE_NAME property.
# for more run 'cmake --help-policy CMP0086'
if(POLICY CMP0086)
  cmake_policy(SET CMP0086 NEW)
endif()

project (
  iriclib
  VERSION 4.0.50
  LANGUAGES CXX C
)

# set standard directory locations
include(GNUInstallDirs)

# # @todo detect Fortran/C interface
# include(FortranCInterface)

if(WIN32)
  set(F2C_INTERFACE "UPPERCASE" CACHE STRING "Fortran/C Interface: LOWERCASE LOWERCASE_ LOWERCASE__ UPPERCASE UPPERCASE_ UPPERCASE__")
else()
  set(F2C_INTERFACE "LOWERCASE_" CACHE STRING "Fortran/C Interface: LOWERCASE LOWERCASE_ LOWERCASE__ UPPERCASE UPPERCASE_ UPPERCASE__")
endif()
set_property(CACHE F2C_INTERFACE PROPERTY STRINGS "LOWERCASE;LOWERCASE_;LOWERCASE__;UPPERCASE;UPPERCASE_;UPPERCASE__")

# Add a d to debug library
set(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "Set Debug library postfix" FORCE)

# Fortran
option(IRICLIB_FORTRAN_TESTING "Build Fortran unittests" ON)
if(IRICLIB_FORTRAN_TESTING)
  enable_language(Fortran)
endif()

find_package(HDF5 1.8 REQUIRED)

find_package(PocoFoundation REQUIRED)

find_package(SWIG REQUIRED)

find_package(Python 3.8 REQUIRED COMPONENTS Interpreter Development)

SET(iriclib_SOURCES
  error_macros.h
  fortran_macros.h
  h5attributecloser.cpp
  h5attributecloser.h
  h5cgnsbase.cpp
  h5cgnsbase.h
  h5cgnsbaseiterativedata.cpp
  h5cgnsbaseiterativedata.h
  h5cgnsbc.cpp
  h5cgnsbc.h
  h5cgnscellflowsolution.cpp
  h5cgnscellflowsolution.h
  h5cgnsconditiongroup.cpp
  h5cgnsconditiongroup.h
  h5cgnsfile.cpp
  h5cgnsfile.h
  h5cgnsfiles.cpp
  h5cgnsfiles.h
  h5cgnsfileseparatesolutionutil.cpp
  h5cgnsfileseparatesolutionutil.h
  h5cgnsfilesolutionreader.cpp
  h5cgnsfilesolutionreader.h
  h5cgnsfilesolutionwriter.cpp
  h5cgnsfilesolutionwriter.h
  h5cgnsflowsolution.cpp
  h5cgnsflowsolution.h
  h5cgnsgeographicdatagroup.cpp
  h5cgnsgeographicdatagroup.h
  h5cgnsgeographicdatatop.cpp
  h5cgnsgeographicdatatop.h
  h5cgnsgridattributes.cpp
  h5cgnsgridattributes.h
  h5cgnsgridcomplexconditiongroup.cpp
  h5cgnsgridcomplexconditiongroup.h
  h5cgnsgridcomplexconditiontop.cpp
  h5cgnsgridcomplexconditiontop.h
  h5cgnsgridcoordinates.cpp
  h5cgnsgridcoordinates.h
  h5cgnsifaceflowsolution.cpp
  h5cgnsifaceflowsolution.h
  h5cgnsjfaceflowsolution.cpp
  h5cgnsjfaceflowsolution.h
  h5cgnskfaceflowsolution.cpp
  h5cgnskfaceflowsolution.h
  h5cgnsnodeflowsolution.cpp
  h5cgnsnodeflowsolution.h
  h5cgnsparticlegroupimagesolution.cpp
  h5cgnsparticlegroupimagesolution.h
  h5cgnsparticlegroupsolution.cpp
  h5cgnsparticlegroupsolution.h
  h5cgnsparticlesolution.cpp
  h5cgnsparticlesolution.h
  h5cgnspolydatasolution.cpp
  h5cgnspolydatasolution.h
  h5cgnssolutioni.h
  h5cgnssolverinformation.cpp
  h5cgnssolverinformation.h
  h5cgnszone.cpp
  h5cgnszone.h
  h5cgnszonebc.cpp
  h5cgnszonebc.h
  h5datasetcloser.cpp
  h5datasetcloser.h
  h5dataspacecloser.cpp
  h5dataspacecloser.h
  h5datatypecloser.cpp
  h5datatypecloser.h
  h5groupcloser.cpp
  h5groupcloser.h
  h5objectcloser.cpp
  h5objectcloser.h
  h5propertylistcloser.cpp
  h5propertylistcloser.h
  h5util.cpp
  h5util.h
  intarraycontainer.cpp
  intarraycontainer.h
  internal/iric_h5cgnsfiles.cpp
  internal/iric_h5cgnsfiles.h
  internal/iric_logger.cpp
  internal/iric_logger.h
  internal/iric_outputerror.cpp
  internal/iric_outputerror.h
  internal/iric_util.cpp
  internal/iric_util.h
  iriclib.h
  iriclib_bc.cpp
  iriclib_bc.h
  iriclib_bstream.cpp
  iriclib_bstream.h
  iriclib_cc.cpp
  iriclib_cc.h
  iriclib_combine.cpp
  iriclib_combine.h
  iriclib_complex.cpp
  iriclib_complex.h
  iriclib_errorcodes.h
  iriclib_ftoc.cpp
  iriclib_geo.cpp
  iriclib_geo.h
  iriclib_geoutil.cpp
  iriclib_geoutil.h
  iriclib_global.h
  iriclib_grid.cpp
  iriclib_grid.h
  iriclib_grid_solverlib.cpp
  iriclib_grid_solverlib.h
  iriclib_gui_coorp.cpp
  iriclib_gui_coorp.h
  iriclib_init.cpp
  iriclib_init.h
  iriclib_not_withbaseid.cpp
  iriclib_not_withbaseid.h
  iriclib_not_withgridid.cpp
  iriclib_not_withgridid.h
  iriclib_pointmap.cpp
  iriclib_pointmap.h
  iriclib_polygon.cpp
  iriclib_polygon.h
  iriclib_polyline.cpp
  iriclib_polyline.h
  iriclib_riversurvey.cpp
  iriclib_riversurvey.h
  iriclib_sol_cell.cpp
  iriclib_sol_cell.h
  iriclib_sol_gridcoord.cpp
  iriclib_sol_gridcoord.h
  iriclib_sol_iface.cpp
  iriclib_sol_iface.h
  iriclib_sol_jface.cpp
  iriclib_sol_jface.h
  iriclib_sol_kface.cpp
  iriclib_sol_kface.h
  iriclib_sol_node.cpp
  iriclib_sol_node.h
  iriclib_sol_particle.cpp
  iriclib_sol_particle.h
  iriclib_sol_particlegroup.cpp
  iriclib_sol_particlegroup.h
  iriclib_sol_particlegroupimage.cpp
  iriclib_sol_particlegroupimage.h
  iriclib_sol_polydata.cpp
  iriclib_sol_polydata.h
  iriclib_solution.cpp
  iriclib_solution.h
  iriclib_wrapper.cpp
  iriclib_wrapper.h
  iricsolverlib_cell2d.cpp
  iricsolverlib_cell2d.h
  iricsolverlib_grid2d.cpp
  iricsolverlib_grid2d.h
  iricsolverlib_point2d.h
  iricsolverlib_quadcell.cpp
  iricsolverlib_quadcell.h
  iricsolverlib_rect2d.cpp
  iricsolverlib_rect2d.h
  iricsolverlib_tricell.cpp
  iricsolverlib_tricell.h
  private/h5cgnsbase_impl.cpp
  private/h5cgnsbase_impl.h
  private/h5cgnsbaseiterativedata_impl.cpp
  private/h5cgnsbaseiterativedata_impl.h
  private/h5cgnsbc_impl.cpp
  private/h5cgnsbc_impl.h
  private/h5cgnsconditiongroup_impl.cpp
  private/h5cgnsconditiongroup_impl.h
  private/h5cgnsfile_impl.cpp
  private/h5cgnsfile_impl.h
  private/h5cgnsfilesolutionreader_impl.cpp
  private/h5cgnsfilesolutionreader_impl.h
  private/h5cgnsfilesolutionwriter_impl.cpp
  private/h5cgnsfilesolutionwriter_impl.h
  private/h5cgnsflowsolution_impl.h
  private/h5cgnsgeographicdatagroup_impl.cpp
  private/h5cgnsgeographicdatagroup_impl.h
  private/h5cgnsgeographicdatatop_impl.cpp
  private/h5cgnsgeographicdatatop_impl.h
  private/h5cgnsgridattributes_impl.cpp
  private/h5cgnsgridattributes_impl.h
  private/h5cgnsgridcomplexconditiongroup_impl.cpp
  private/h5cgnsgridcomplexconditiongroup_impl.h
  private/h5cgnsgridcomplexconditiontop_impl.cpp
  private/h5cgnsgridcomplexconditiontop_impl.h
  private/h5cgnsgridcoordinates_impl.cpp
  private/h5cgnsgridcoordinates_impl.h
  private/h5cgnsparticlegroupsolution_impl.cpp
  private/h5cgnsparticlegroupsolution_impl.h
  private/h5cgnsparticlegroupimagesolution_impl.cpp
  private/h5cgnsparticlegroupimagesolution_impl.h
  private/h5cgnsparticlesolution_impl.h
  private/h5cgnspolydatasolution_impl.cpp
  private/h5cgnspolydatasolution_impl.h
  private/h5cgnssolverinformation_impl.cpp
  private/h5cgnssolverinformation_impl.h
  private/h5cgnszone_impl.cpp
  private/h5cgnszone_impl.h
  private/h5cgnszonebc_impl.cpp
  private/h5cgnszonebc_impl.h
  private/iricsolverlib_cell2d_impl.h
  private/iricsolverlib_grid2d_impl.h
  private/iricsolverlib_point2d_detail.h
  private/vectorutil_detail.h
  public/h5cgnsparticlegroupsolution_groupreader.cpp
  public/h5cgnsparticlegroupsolution_groupreader.h
  public/h5cgnspolydatasolution_groupreader.cpp
  public/h5cgnspolydatasolution_groupreader.h
  realarraycontainer.cpp
  realarraycontainer.h
  vectorutil.h
)

# iriclib target
add_library(iriclib SHARED ${iriclib_SOURCES})

# iriclib compile features
target_compile_features(iriclib
  PRIVATE
    cxx_std_11
)

# iriclib compile definitions
target_compile_definitions(iriclib
  PRIVATE
    $<$<BOOL:MSVC>:_CRT_SECURE_NO_DEPRECATE>
    $<$<BOOL:MSVC>:_SCL_SECURE_NO_WARNINGS>
    IRICLIBDLL_LIBRARY
    IRICSOLVERLIBDLL_LIBRARY
    ${F2C_INTERFACE}
)

# this works except it also adds iric.f90 to CXX/C projects
target_sources(iriclib
  INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/iric.f90>"
    "$<INSTALL_INTERFACE:src/iric.f90>"
)

# iriclib include directories
target_include_directories(iriclib
  PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/private>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

# iriclib link libraries
target_link_libraries(iriclib
  PRIVATE
    hdf5::hdf5-shared           #  ${HDF5_LIBRARIES}  @todo test non-windows builds
    Poco::Foundation
)

SET(iriclib_Headers
  ${PROJECT_SOURCE_DIR}/error_macros.h
  ${PROJECT_SOURCE_DIR}/fortran_macros.h
  ${PROJECT_SOURCE_DIR}/h5attributecloser.h
  ${PROJECT_SOURCE_DIR}/h5cgnsbase.h
  ${PROJECT_SOURCE_DIR}/h5cgnsbaseiterativedata.h
  ${PROJECT_SOURCE_DIR}/h5cgnsbc.h
  ${PROJECT_SOURCE_DIR}/h5cgnscellflowsolution.h
  ${PROJECT_SOURCE_DIR}/h5cgnsconditiongroup.h
  ${PROJECT_SOURCE_DIR}/h5cgnsfile.h
  ${PROJECT_SOURCE_DIR}/h5cgnsfiles.h
  ${PROJECT_SOURCE_DIR}/h5cgnsfileseparatesolutionutil.h
  ${PROJECT_SOURCE_DIR}/h5cgnsfilesolutionreader.h
  ${PROJECT_SOURCE_DIR}/h5cgnsfilesolutionwriter.h
  ${PROJECT_SOURCE_DIR}/h5cgnsflowsolution.h
  ${PROJECT_SOURCE_DIR}/h5cgnsgeographicdatagroup.h
  ${PROJECT_SOURCE_DIR}/h5cgnsgeographicdatatop.h
  ${PROJECT_SOURCE_DIR}/h5cgnsgridattributes.h
  ${PROJECT_SOURCE_DIR}/h5cgnsgridcomplexconditiongroup.h
  ${PROJECT_SOURCE_DIR}/h5cgnsgridcomplexconditiontop.h
  ${PROJECT_SOURCE_DIR}/h5cgnsgridcoordinates.h
  ${PROJECT_SOURCE_DIR}/h5cgnsifaceflowsolution.h
  ${PROJECT_SOURCE_DIR}/h5cgnsjfaceflowsolution.h
  ${PROJECT_SOURCE_DIR}/h5cgnskfaceflowsolution.h
  ${PROJECT_SOURCE_DIR}/h5cgnsnodeflowsolution.h
  ${PROJECT_SOURCE_DIR}/h5cgnsparticlegroupsolution.h
  ${PROJECT_SOURCE_DIR}/h5cgnsparticlegroupimagesolution.h
  ${PROJECT_SOURCE_DIR}/h5cgnsparticlesolution.h
  ${PROJECT_SOURCE_DIR}/h5cgnspolydatasolution.h
  ${PROJECT_SOURCE_DIR}/h5cgnssolutioni.h
  ${PROJECT_SOURCE_DIR}/h5cgnssolverinformation.h
  ${PROJECT_SOURCE_DIR}/h5cgnszone.h
  ${PROJECT_SOURCE_DIR}/h5cgnszonebc.h
  ${PROJECT_SOURCE_DIR}/h5datasetcloser.h
  ${PROJECT_SOURCE_DIR}/h5dataspacecloser.h
  ${PROJECT_SOURCE_DIR}/h5datatypecloser.h
  ${PROJECT_SOURCE_DIR}/h5groupcloser.h
  ${PROJECT_SOURCE_DIR}/h5objectcloser.h
  ${PROJECT_SOURCE_DIR}/h5propertylistcloser.h
  ${PROJECT_SOURCE_DIR}/h5util.h
  ${PROJECT_SOURCE_DIR}/intarraycontainer.h
  ${PROJECT_SOURCE_DIR}/iriclib.h
  ${PROJECT_SOURCE_DIR}/iriclib_bc.h
  ${PROJECT_SOURCE_DIR}/iriclib_bstream.h
  ${PROJECT_SOURCE_DIR}/iriclib_cc.h
  ${PROJECT_SOURCE_DIR}/iriclib_combine.h
  ${PROJECT_SOURCE_DIR}/iriclib_complex.h
  ${PROJECT_SOURCE_DIR}/iriclib_errorcodes.h
  ${PROJECT_SOURCE_DIR}/iriclib_geo.h
  ${PROJECT_SOURCE_DIR}/iriclib_geoutil.h
  ${PROJECT_SOURCE_DIR}/iriclib_global.h
  ${PROJECT_SOURCE_DIR}/iriclib_grid.h
  ${PROJECT_SOURCE_DIR}/iriclib_grid_solverlib.h
  ${PROJECT_SOURCE_DIR}/iriclib_gui_coorp.h
  ${PROJECT_SOURCE_DIR}/iriclib_init.h
  ${PROJECT_SOURCE_DIR}/iriclib_not_withbaseid.h
  ${PROJECT_SOURCE_DIR}/iriclib_not_withgridid.h
  ${PROJECT_SOURCE_DIR}/iriclib_pointmap.h
  ${PROJECT_SOURCE_DIR}/iriclib_polygon.h
  ${PROJECT_SOURCE_DIR}/iriclib_polyline.h
  ${PROJECT_SOURCE_DIR}/iriclib_riversurvey.h
  ${PROJECT_SOURCE_DIR}/iriclib_sol_cell.h
  ${PROJECT_SOURCE_DIR}/iriclib_sol_gridcoord.h
  ${PROJECT_SOURCE_DIR}/iriclib_sol_iface.h
  ${PROJECT_SOURCE_DIR}/iriclib_sol_jface.h
  ${PROJECT_SOURCE_DIR}/iriclib_sol_kface.h
  ${PROJECT_SOURCE_DIR}/iriclib_sol_node.h
  ${PROJECT_SOURCE_DIR}/iriclib_sol_particle.h
  ${PROJECT_SOURCE_DIR}/iriclib_sol_particlegroup.h
  ${PROJECT_SOURCE_DIR}/iriclib_sol_particlegroupimage.h
  ${PROJECT_SOURCE_DIR}/iriclib_sol_polydata.h
  ${PROJECT_SOURCE_DIR}/iriclib_solution.h
  ${PROJECT_SOURCE_DIR}/iriclib_wrapper.h
  ${PROJECT_SOURCE_DIR}/iricsolverlib_cell2d.h
  ${PROJECT_SOURCE_DIR}/iricsolverlib_grid2d.h
  ${PROJECT_SOURCE_DIR}/iricsolverlib_point2d.h
  ${PROJECT_SOURCE_DIR}/iricsolverlib_quadcell.h
  ${PROJECT_SOURCE_DIR}/iricsolverlib_rect2d.h
  ${PROJECT_SOURCE_DIR}/iricsolverlib_tricell.h
  ${PROJECT_SOURCE_DIR}/realarraycontainer.h
  ${PROJECT_SOURCE_DIR}/vectorutil.h
)

SET(iriclib_internal_Headers
  ${PROJECT_SOURCE_DIR}/internal/iric_h5cgnsfiles.h
  ${PROJECT_SOURCE_DIR}/internal/iric_logger.h
  ${PROJECT_SOURCE_DIR}/internal/iric_outputerror.h
  ${PROJECT_SOURCE_DIR}/internal/iric_util.h
)

SET(iriclib_private_Headers
  ${PROJECT_SOURCE_DIR}/private/h5cgnsbase_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsbaseiterativedata_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsbc_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsconditiongroup_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsfile_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsfilesolutionreader_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsfilesolutionwriter_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsflowsolution_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsgeographicdatagroup_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsgeographicdatatop_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsgridattributes_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsgridcomplexconditiongroup_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsgridcomplexconditiontop_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsgridcoordinates_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsparticlegroupsolution_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsparticlegroupimagesolution_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnsparticlesolution_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnspolydatasolution_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnssolverinformation_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnszone_impl.h
  ${PROJECT_SOURCE_DIR}/private/h5cgnszonebc_impl.h
  ${PROJECT_SOURCE_DIR}/private/iricsolverlib_cell2d_impl.h
  ${PROJECT_SOURCE_DIR}/private/iricsolverlib_grid2d_impl.h
  ${PROJECT_SOURCE_DIR}/private/iricsolverlib_point2d_detail.h
  ${PROJECT_SOURCE_DIR}/private/vectorutil_detail.h
)

SET(iriclib_public_Headers
  ${PROJECT_SOURCE_DIR}/public/h5cgnsparticlegroupsolution_groupreader.h
  ${PROJECT_SOURCE_DIR}/public/h5cgnspolydatasolution_groupreader.h
)

# setup for configure_package_config_file
set(exportPackageDependencies "")
string(APPEND exportPackageDependencies "find_dependency(HDF5)\n")
string(APPEND exportPackageDependencies "find_dependency(PocoFoundation)\n")

include(CMakePackageConfigHelpers)

configure_package_config_file(iriclibConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/iriclibConfig.cmake
  INSTALL_DESTINATION cmake/iriclib
)

write_basic_package_version_file("iriclibConfigVersion.cmake"
  VERSION ${iriclib_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/iriclibConfig.cmake ${CMAKE_CURRENT_BINARY_DIR}/iriclibConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/iriclib
)

# install
install(TARGETS iriclib
  EXPORT   iriclibTargets
  LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT iriclibTargets
  FILE iriclibTargets.cmake
  NAMESPACE iriclib::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/iriclib
)

install(FILES ${iriclib_Headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${iriclib_internal_Headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/internal)
install(FILES ${iriclib_private_Headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/private)
install(FILES ${iriclib_public_Headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/public)

if(MSVC)
  install(FILES $<TARGET_PDB_FILE:iriclib>
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
    CONFIGURATIONS Debug RelWithDebInfo)
endif()

install(FILES ${PROJECT_SOURCE_DIR}/iric.f90 DESTINATION src)           # @todo check non-windows builds

add_library(iriclib::iriclib ALIAS iriclib)

add_subdirectory(python_binding)

include(CTest)

if(BUILD_TESTING)
  add_subdirectory(unittests_cgnsfile)
  if(IRICLIB_FORTRAN_TESTING)
    add_subdirectory(unittests)
  endif()
  # add_subdirectory(unittest_lock)
  # add_subdirectory(unittest_cg_open_modify)
  # add_subdirectory(unittest_cg_open_read)
  # add_subdirectory(unittests_h5)
endif()

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#   message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()
