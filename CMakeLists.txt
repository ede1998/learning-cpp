cmake_minimum_required(VERSION 3.7)
project(programming_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp User.cpp User.h LoginController.cpp LoginController.h Menu.cpp Menu.h Account.cpp Account.h CheckAccount.cpp CheckAccount.h BuildingLoanContract.cpp BuildingLoanContract.h InstantAccessSavingsAccount.cpp InstantAccessSavingsAccount.h)
add_executable(programming_cpp ${SOURCE_FILES})