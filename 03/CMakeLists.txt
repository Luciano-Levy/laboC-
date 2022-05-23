cmake_minimum_required(VERSION 3.14)
project(03)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(03
        src/generador.cpp
        src/generador.h
        src/main.cpp
        src/vectores.cpp
        src/vectores.h
        src/lecturaEscritura.cpp
        src/lecturaEscritura.h)
