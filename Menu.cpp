//
// Created by erik on 18.05.17.
//

#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {
    m_lc = new LoginController();
}

Menu::~Menu() {
    delete m_lc;
}

void Menu::printMain() {
    cout << "Main Menu:" << endl;
    cout << "Please choose an action" << endl;
    cout << "(0) Login" << endl;
    cout << "(1) Create new account" << endl;
    cout << "(2) Quit program" << endl;
}

void Menu::createAccount() {
    string name, pwd;
    cout << "Please enter name: ";
    cin >> name;
    cout << "Please enter password: ";
    cin >> pwd;
    m_lc->addUser(name, pwd);
}

void Menu::login() {
    string name, pwd;
    cout << "Please enter login credentials." << endl;
    cout << "User: ";
    cin >> name;
    cout << "Password: ";
    cin >> pwd;
    if (m_lc->login(name, pwd)) {
        cout << "Successfully logged in as user " << m_lc->loggedInAs() << "." << endl;
    }
    else {
        cout << "Wrong username or password." << endl;
    }
}


bool Menu::main() {
    int option;
    printMain();
    cin >> option;
    switch (option) {
        case 0: //Login
            login();
            break;
        case 1: //Create Account
            createAccount();
            break;
        case 2: //Quit program
            return false;
        }
    return true;
}
