//
// Created by erik on 18.05.17.
//

#include "Menu.h"
#include <iostream>
#include "accounts/CheckAccount.h"
#include "accounts/BuildingLoanContract.h"
#include "accounts/InstantAccessSavingsAccount.h"

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
    cout << "(1) Create new user account" << endl;
    cout << "(2) Quit program" << endl;
}

void Menu::createUserAccount() {
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
        manageAccounts();
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
            createUserAccount();
            break;
        case 2: //Quit program
            return false;
        }
    return true;
}

void Menu::showAccounts() {
    User * user = m_lc->loggedInAs();
    cout << "List of accounts:" << endl;
    cout << "Type\tNumber\tBank-Code\tBalance" << endl;
    for (int i = 0; i < user->getAccountsLength(); i++) {
        const Account * acc = user->getAccount(i);
        cout << CheckAccount::name << "\t" << acc->accountNumber << "\t" << acc->bankCode << "\t" << acc->getBalance() << endl;
    }

}

void Menu::manageAccounts() {
    bool logout = false;
    while (!logout) {
        cout << "Account Manager:" << endl;
        cout << "Please choose an action" << endl;
        cout << "(0) Display account information" << endl;
        cout << "(1) Transaction" << endl;
        cout << "(2) Create new bank account" << endl;
        cout << "(3) Logout" << endl;
        int action = -1;
        cin >> action;
        switch (action) {
            case 0:
                showAccounts();
                break;
            case 1:
                break;
            case 2:
                createBankAccount();
                break;
            case 3:
                logout = true;
                break;
        }
    }
}

void Menu::createBankAccount() {
    //owner contact bankcode
    string bankCode;
    int accType = -1;
    int nr;
    bool accSelected;
    cout << "Creating new bank account:" << endl;
    cout << "Please enter bank-code: ";
    cin >> bankCode;
    cout << "There are 3 types to choose from:" << endl;
    cout << "Type 1: " << CheckAccount::name << endl;
    cout << CheckAccount::description << endl;
    cout << "Type 2: " << BuildingLoanContract::name << endl;
    cout << BuildingLoanContract::description << endl;
    cout << "Type 3: " << InstantAccessSavingsAccount::name << endl;
    cout << InstantAccessSavingsAccount::description << endl;
    cout << "Please choose an account type:" << endl;
    do {
        cin >> accType;
        accSelected = true;
        switch (accType) {
            case 1:
                cout << "Please enter overdraft:" << endl;
                cin >> nr;
                m_lc->loggedInAs()->addAccount(
                        CheckAccount(m_lc->loggedInAs(), nullptr, bankCode, nr));
                break;
            case 2:
                cout << "Please enter savings sum:" << endl;
                cin >> nr;
                m_lc->loggedInAs()->addAccount(
                        BuildingLoanContract(m_lc->loggedInAs(), nullptr, bankCode, nr));
                break;
            case 3:
                cout << "Please enter minimum term:" << endl;
                cin >> nr;
                m_lc->loggedInAs()->addAccount(
                        InstantAccessSavingsAccount(m_lc->loggedInAs(), nullptr, bankCode, nr));
                break;
            default:
                accSelected = false;
                break;
        }
    } while (!accSelected);
}
