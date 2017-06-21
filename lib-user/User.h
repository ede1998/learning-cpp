//
// Created by erik on 11.05.17.
//

#pragma once

#include <string>
#include <unistd.h>
#include <vector>
#include "../lib-accounts/Account.h"
#include "../Loader.h"

using namespace std;

class Account;

class User {
public:
    User(const string &m_name, const string &pwd);
    ~User();
    string getName();
    bool isCorrectPassword(string pwd);
    int getAccount(int index);
    weak_ptr<Account> getAccountById(int id);
    int getAccountsLength();
    void addAccount(const int ID);
    void removeAccount(const int index);
    string serialize();
    static unique_ptr<User> unserialize(string serializedObj);
private:
    User(const string &m_name, const string &pwd, char dummy);
    string m_name;
    string m_pwd;
    vector<int> m_accounts;
};
