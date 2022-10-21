cmake_minimum_required(VERSION 3.7)

project(sqlite-preprocessed-3390400)

add_definitions(-DSQLITE_CORE=1 -DSQLITE_DEBUG)

FILE(GLOB SRCS *.c)
LIST(FILTER SRCS EXCLUDE REGEX "(tclsqlite.c|geopoly.c|lempar.c|lemon.c)$")
add_executable(main ${SRCS})
add_executable(lemon lemon.c)
