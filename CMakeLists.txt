# 最低 CMake 版本要求
cmake_minimum_required(VERSION 3.22)
# 项目名称
project(CLIB_Shared)
# C++ 语言标准
set(CMAKE_CXX_STANDARD 17)

# 编译为静态库，并指定库源码文件
add_library(
        CLIB_Shared STATIC

        library.cpp
        net/play5d/utils/WStringUtils.cpp
)
