cmake_minimum_required(VERSION 3.6)
project(LaboMatrices)

#set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)


set(SOURCE_FILES main.cpp
        cases.cpp
        ejercicios.cpp)

add_executable(LaboMatrices ${SOURCE_FILES})

target_link_libraries(LaboMatrices gtest gtest_main)
