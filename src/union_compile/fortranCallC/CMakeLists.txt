cmake_minimum_required(VERSION 2.8.5)
project(main)
enable_language(Fortran)
set(CMAKE_BUILD_TYPE Release)
set(sources
        main.f90
        api.f90
        func.c
)
add_executable(main ${sources})