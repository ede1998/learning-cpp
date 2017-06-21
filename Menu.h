//
// Created by erik on 18.05.17.
//

#pragma once
#include "lib-user/LoginController.h"
#include "lib-accounts/BankController.h"

class Menu {
public:
    Menu();
    ~Menu();
    bool main();
private:
    LoginController *m_lc;
    BankController *m_bc;

    void login();
    void createUserAccount();
    void printMain();
    void showAccounts();

    void manageAccounts();

    void createBankAccount();

    void deleteBankAccount();
};

