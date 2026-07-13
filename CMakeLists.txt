cmake_minimum_required(VERSION 3.0)

project(mw_plugin)

set(CMAKE_C_STANDARD 11)

include_directories(inc)

add_subdirectory(src)
add_subdirectory(test)