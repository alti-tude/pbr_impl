cmake_minimum_required(VERSION 3.17.0)
project(pbr_implementation)

add_subdirectory(src)
add_definitions(-DUSE_DOUBLE)
enable_testing()
add_subdirectory(tests)