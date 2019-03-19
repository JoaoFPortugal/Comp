cmake_minimum_required(VERSION 3.13)
project(Projecto)

set(CMAKE_CXX_STANDARD 14)

include_directories(lib)

add_executable(Projecto
        lib/main.c
        lib/node.c
        lib/node.h
        lib/postfix.h
        lib/tabid.c
        lib/tabid.h
        diy.brg
        diy.l
        diy.y
        Makefile)
