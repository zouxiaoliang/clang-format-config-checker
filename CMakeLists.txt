cmake_minimum_required(VERSION 3.5)

project(clang-format-config-checker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 如果使用其他版本的LLVM，需要调整的LLVM路径
set(llvm_home /usr/local/opt/llvm@9/)
message(STATUS "llvm: ${llvm_home}")

include_directories(${llvm_home}/include)
link_directories(${llvm_home}/lib)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} LLVM clangFormat clangToolingInclusions clangToolingCore clangRewrite clangLex clangBasic clang-cpp)
