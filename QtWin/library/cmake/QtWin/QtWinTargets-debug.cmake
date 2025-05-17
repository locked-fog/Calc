#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "QtWin::QtWin" for configuration "Debug"
set_property(TARGET QtWin::QtWin APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(QtWin::QtWin PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/library/libQtWin.dll.a"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/library/libQtWin.dll"
  )

list(APPEND _cmake_import_check_targets QtWin::QtWin )
list(APPEND _cmake_import_check_files_for_QtWin::QtWin "${_IMPORT_PREFIX}/library/libQtWin.dll.a" "${_IMPORT_PREFIX}/library/libQtWin.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
