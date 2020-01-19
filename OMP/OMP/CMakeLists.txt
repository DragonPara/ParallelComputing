cmake_minimum_required(VERSION 3.15)
project(Test1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test1 main.c)

FIND_PACKAGE(OpenMP REQUIRED)
    if(OPENMP_FOUND)
        set(CMAKE_C_FLAGS "${OpenMP_C_FLAGS}")
    endif()