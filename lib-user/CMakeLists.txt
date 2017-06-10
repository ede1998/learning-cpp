cmake_minimum_required(VERSION 3.7)
project(lib_user)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES library.cpp library.h)
add_library(lib_user ${SOURCE_FILES})