//
// Created by erik on 18.05.17.
//

#pragma once
#include "LoginController.h"

class Menu {
public:
    Menu();
    ~Menu();
    bool main();
private:
    LoginController * m_lc;



    void login();
    void createAccount();
    void printMain();
};

