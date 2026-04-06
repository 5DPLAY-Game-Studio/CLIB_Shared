# 最低 CMake 版本要求
cmake_minimum_required(VERSION 3.22)
# 项目名称
project(CLIB_Shared)
# C++ 语言标准
set(CMAKE_CXX_STANDARD 17)
# 定义一个源码根目录变量
set(SRC_DIR ${PROJECT_SOURCE_DIR}/source)

# 头文件搜索路径
include_directories("${SRC_DIR}")
# 编译为静态库，并指定库源码文件
add_library(
        CLIB_Shared STATIC

        library.cpp
        ${SRC_DIR}/net/play5d/utils/JsonUtils.cpp
        ${SRC_DIR}/net/play5d/utils/WStringUtils.cpp
)

# 设置使用此库的公开头文件搜索路径
target_include_directories(
        CLIB_Shared PUBLIC

        ${SRC_DIR}
)