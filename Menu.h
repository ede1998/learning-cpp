//
// Created by erik on 18.05.17.
//

#pragma once
#include "user/LoginController.h"
#include "accounts/BankController.h"

class Menu {
public:
    Menu();
    ~Menu();
    bool main();
private:
    LoginController m_lc;
    BankController m_bc;

    void login();
    void createUserAccount();
    void printMain();
    void showAccounts();

    void manageAccounts();

    void createBankAccount();

    void deleteBankAccount();
};

