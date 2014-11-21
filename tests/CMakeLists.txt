file(GLOB TEST_SOURCES *.c)
include_directories(${CMAKE_SOURCE_DIR}) #for newtan.h
add_executable(mytest ${TEST_SOURCES})
target_link_libraries(mytest mym)

#add_test (TestRuns mytest 1)

add_test (Test2 mytest 2)
set_tests_properties (Test2 PROPERTIES PASS_REGULAR_EXPRESSION "-2.185040")