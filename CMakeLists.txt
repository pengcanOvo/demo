# cmake_minimum_required(VERSION <specify CMake version here>)
project(demo1)

set(CMAKE_CXX_STANDARD 14)

add_executable(demo1 main.cpp demo.h demo.cpp global.h Person.cpp Person.h Phone.cpp Phone.h Calculator.cpp Calculator.h add.cpp)