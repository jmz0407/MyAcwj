cmake_minimum_required(VERSION 3.22)
project(MyAcwj)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyAcwj scan.cpp interp.cpp expr.cpp tree.cpp main.cpp)