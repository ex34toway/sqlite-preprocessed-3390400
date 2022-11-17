cmake_minimum_required(VERSION 3.7)

project(sqlite-preprocessed-3390400)

add_definitions(-DSQLITE_CORE=1 -DSQLITE_DEBUG)

FILE(GLOB SRCS *.c)
LIST(FILTER SRCS EXCLUDE REGEX "(tclsqlite.c|geopoly.c|lempar.c|lemon.c|calc.c|calc_main.c|calc2.c|calc2_main.c)$")
add_executable(main ${SRCS})
add_executable(lemon lemon.c)
add_executable(calc calc_main.c)
add_executable(calc2 calc2_main.c)
