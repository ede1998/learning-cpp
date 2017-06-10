//
// Created by erik on 18.05.17.
//

#include "Menu.h"
#include <iostream>
#include "lib-accounts/CheckAccount.h"
#include "lib-accounts/BuildingLoanContract.h"
#include "lib-accounts/InstantAccessSavingsAccount.h"

using namespace std;

Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::printMain() {
    cout << "Main Menu:" << endl;
    cout << "Please choose an action" << endl;
    cout << "(0) Quit program" << endl;
    cout << "(1) Login" << endl;
    cout << "(2) Create new user account" << endl;
}

void Menu::createUserAccount() {
    string name, pwd;
    cout << "Please enter name: ";
    cin >> name;
    cout << "Please enter password: ";
    cin >> pwd;
    m_lc.addUser(name, pwd);
}

void Menu::login() {
    string name, pwd;
    cout << "Please enter login credentials." << endl;
    cout << "User: ";
    cin >> name;
    cout << "Password: ";
    cin >> pwd;
    if (m_lc.login(name, pwd)) {
        cout << "Successfully logged in as user " << m_lc.loggedInAs()->getName() << "." << endl;
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
        case 1: //Login
            login();
            break;
        case 2: //Create Account
            createUserAccount();
            break;
        case 0: //Quit program
            return false;
        }
    return true;
}

void Menu::showAccounts() {
    shared_ptr<User> user = m_lc.loggedInAs();
    cout << "List of accounts:" << endl;
    cout << "NR\tType\tNumber\tBank-Code\tBalance" << endl;
    for (int i = 0; i < user->getAccountsLength(); i++) {
        const shared_ptr<Account> acc = user->getAccount(i).lock();
        cout << i+1 << "\t" << acc->getName() << "\t" << acc->accountNumber << "\t" << acc->bankCode << "\t" << acc->getBalance() << endl;
    }

}

void Menu::manageAccounts() {
    bool logout = false;
    while (!logout) {
        cout << "Account Manager:" << endl;
        cout << "Please choose an action" << endl;
        cout << "(0) Logout" << endl;
        cout << "(1) Display account information" << endl;
        cout << "(2) Transaction" << endl;
        cout << "(3) Create new bank account" << endl;
        cout << "(4) Delete bank account" << endl;
        int action = -1;
        cin >> action;
        switch (action) {
            case 1:
                showAccounts();
                break;
            case 2:
                break;
            case 3:
                createBankAccount();
                break;
            case 4:
                deleteBankAccount();
                break;
            case 0:
                logout = true;
                break;
        }
    }
}

void Menu::createBankAccount() {
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

                m_lc.loggedInAs()->addAccount(
                        m_bc.createCheckAccount(m_lc.loggedInAs(), nullptr, bankCode, nr));
                break;
            case 2:
                cout << "Please enter savings sum:" << endl;
                cin >> nr;
                m_lc.loggedInAs()->addAccount(
                        m_bc.createBuildingLoanContract(m_lc.loggedInAs(), nullptr, bankCode, nr));
                break;
            case 3:
                cout << "Please enter minimum term:" << endl;
                cin >> nr;
                m_lc.loggedInAs()->addAccount(
                        m_bc.createInstantAccessSavingsAccount(m_lc.loggedInAs(), nullptr, bankCode, nr));
                break;
            default:
                accSelected = false;
                break;
        }
    } while (!accSelected);
}

void Menu::deleteBankAccount() {
    if (m_lc.loggedInAs()->getAccountsLength() == 0) {
        cout << "No accounts exist." << endl;
        return;
    }
    cout << "Delete bank account:" << endl;
    cout << "Please choose an account: (-1 to cancel)" << endl;
    showAccounts();
    int nr;
    cin >> nr;
    m_bc.deleteAccount(--nr);
}
