cmake_minimum_required(VERSION 3.12.4)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(operators)

add_executable(operators main.cpp op_test.cpp op_test.h)