cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

#============================================================================
# Initialize the project
#============================================================================
project(tests_dl)

add_library(hello SHARED hello.cpp)
add_library(dynamic_load_cmake SHARED dynamic_load_cmake.cpp)

add_executable(main_dl main_dl.cpp)
target_link_libraries(main_dl dl)

add_executable(main_dl_link_cmake main_dl_link_cmake.cpp)
target_link_libraries(main_dl_link_cmake dl hello)
