cmake_minimum_required(VERSION 3.7)
project(programming_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp user/User.cpp user/User.h user/LoginController.cpp user/LoginController.h Menu.cpp Menu.h accounts/Account.cpp accounts/Account.h accounts/CheckAccount.cpp accounts/CheckAccount.h accounts/BuildingLoanContract.cpp accounts/BuildingLoanContract.h accounts/InstantAccessSavingsAccount.cpp accounts/InstantAccessSavingsAccount.h)
add_executable(programming_cpp ${SOURCE_FILES})