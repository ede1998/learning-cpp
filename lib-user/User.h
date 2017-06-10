//
// Created by erik on 11.05.17.
//

#pragma once

#include <string>
#include <unistd.h>
#include <vector>
#include "../lib-accounts/Account.h"

using namespace std;

class Account;

class User {
public:
    User(const string &m_name, const string &pwd);
    ~User();
    string getName();
    bool isCorrectPassword(string pwd);
    weak_ptr<Account> getAccount(int index);
    int getAccountsLength();
    void addAccount(const weak_ptr<Account> acc);
    void removeAccount(const int index);
private:
    string m_name;
    string m_pwd;
    vector<weak_ptr<Account>> m_accounts;
};
