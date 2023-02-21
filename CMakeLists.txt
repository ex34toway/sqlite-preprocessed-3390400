cmake_minimum_required(VERSION 3.7)

project(sqlite-preprocessed-3390400)

add_definitions(-DSQLITE_CORE=1 -DSQLITE_DEBUG -DSQLITE_ENABLE_SELECTTRACE)

FILE(GLOB SRCS *.c)
LIST(FILTER SRCS EXCLUDE REGEX "(shell.c|tclsqlite.c|geopoly.c|lempar.c|lemon.c|dbtotxt.c|calc.c|calc_main.c|calc2.c|calc2_main.c)$")
add_library(sqlite3 STATIC ${SRCS})

add_executable(main ${SRCS} shell.c)
target_link_libraries(main PRIVATE sqlite3)

add_executable(lemon lemon.c)
add_executable(dbtotxt dbtotxt.c)
add_executable(calc calc_main.c)
add_executable(calc2 calc2_main.c)

add_executable(test_case_select test_case_select.cpp)
target_link_libraries(test_case_select PRIVATE sqlite3)
target_include_directories(test_case_select PRIVATE "${CMAKE_SOURCE_DIR}")
