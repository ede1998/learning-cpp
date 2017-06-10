cmake_minimum_required(VERSION 3.7)
project(lib_accounts)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Account.cpp Account.h CheckAccount.cpp CheckAccount.h BankController.h BankController.cpp BuildingLoanContract.cpp BuildingLoanContract.h InstantAccessSavingsAccount.h InstantAccessSavingsAccount.cpp)
add_library(lib_accounts ${SOURCE_FILES})