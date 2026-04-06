# 最低 CMake 版本要求
cmake_minimum_required(VERSION 3.22)
# 项目名称
project(CLIB_Shared)
# C++ 语言标准
set(CMAKE_CXX_STANDARD 11)

add_library(CLIB_Shared library.cpp)
