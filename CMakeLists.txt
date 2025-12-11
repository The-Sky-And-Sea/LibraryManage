# 设置CMake的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(DataStructReview)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 添加所有源文件
file(GLOB SOURCES "src/*.cpp")

# 包含头文件目录
include_directories(include)

# 添加可执行文件
add_executable(preview ${SOURCES})