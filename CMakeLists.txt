cmake_minimum_required(VERSION 3.7)
project(programming_cpp)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib-accounts)
add_subdirectory(lib-user)

set(SOURCE_FILES main.cpp Menu.cpp Menu.h Loader.cpp Loader.h)

add_executable(programming_cpp ${SOURCE_FILES})
target_link_libraries(programming_cpp lib_user)
target_link_libraries(programming_cpp lib_accounts)