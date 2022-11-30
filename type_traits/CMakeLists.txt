cmake_minimum_required(VERSION 3.13)

project(type_sizes)
set(CMAKE_CXX_STANDARD 17)
set(BOOST_ROOT "C:/Boost")
add_executable(type_sizes type_sizes.cpp)
find_package(Boost REQUIRED)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
