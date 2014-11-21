cmake_minimum_required(VERSION 2.8)

project(mym)
enable_testing()
set(LIB lib)
set(SOVERSION 1)
set(CMAKE_INSTALL_PREFIX .)
set(MATH_LIBRARIES "m" CACHE STRING "math library")


#file(GLOB MYM_SOURCES *.c)

add_library(mym SHARED libmym.c)
target_link_libraries(mym ${MATH_LIBRARIES})

add_executable (main main.c)
target_link_libraries (main LINK_PUBLIC mym)
install(TARGETS mym LIBRARY DESTINATION ${LIB} ARCHIVE DESTINATION ${LIB})

#optional
set_target_properties(mym PROPERTIES SOVERSION ${SOVERSION}) #optional
configure_file(libmym.pc.in ${CMAKE_CURRENT_BINARY_DIR}/libmym.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libmym.pc DESTINATION ${LIB}/pkgconfig)

add_subdirectory(tests)
