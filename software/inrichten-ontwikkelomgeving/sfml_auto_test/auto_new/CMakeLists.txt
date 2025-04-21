cmake_minimum_required(VERSION 3.16)
project(auto_new)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use LLVM clang (Homebrew)
set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")

# Let CMake know where to find SFML 3
set(CMAKE_PREFIX_PATH "/opt/homebrew")

find_package(SFML 3 REQUIRED COMPONENTS Graphics)

add_executable(auto_new main.cpp)

target_link_libraries(auto_new SFML::Graphics)
