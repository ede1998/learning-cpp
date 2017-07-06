cmake_minimum_required(VERSION 3.7)
project(programming_cpp)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib-accounts)
add_subdirectory(lib-user)

set(SOURCE_FILES Menu.cpp Menu.h Loader.cpp Loader.h)
message(${CMAKE_BUILD_TYPE})

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(SOURCE_FILES ${SOURCE_FILES} main.cpp)
endif(${CMAKE_BUILD_TYPE} STREQUAL "Debug")

if (${CMAKE_BUILD_TYPE} STREQUAL "test")
    message("Hello world")
    set(SOURCE_FILES ${SOURCE_FILES} unittests.h unittests.cpp catch.hpp)
endif(${CMAKE_BUILD_TYPE} STREQUAL "test")

message(${SOURCE_FILES})

add_executable(programming_cpp ${SOURCE_FILES})
target_link_libraries(programming_cpp lib_user)
target_link_libraries(programming_cpp lib_accounts)