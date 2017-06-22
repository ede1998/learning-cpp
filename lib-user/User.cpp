//
// Created by erik on 11.05.17.
//

#include "User.h"
#include "../lib-accounts/BankController.h"
#include "md5.h"

/**
 * Constructor of class User. Creates a new User and takes a username and a password as parameter.
 * Only a hash of the password is stored.
 * @param m_name Username
 * @param pwd Password for the user
 */
User::User(const string &m_name, const string &pwd) : m_name(m_name) {
    m_pwd = md5(pwd);
}

User::User(const string &m_name, const string &pwd, char dummy) : m_name(m_name) {
    m_pwd = pwd;
}

User::~User() {

}
/**
 * Compares the hash of parameter pwd with the internally stored password hash.
 * @param pwd The password to compare
 * @return Returns true if password hashes equal, false otherwise
 */
bool User::isCorrectPassword(string pwd) {
    return  md5(pwd) == m_pwd;
}
/**
 * Returns the username.
 * @return Username
 */
string User::getName() {
    return m_name;
}

int User::getAccountsLength() {
    return m_accounts.size();
}

int User::getAccount(int index) {
    if ((index < 0) || (index >= m_accounts.size())) {
        return -1;
    }
    return m_accounts[index];
}

weak_ptr<Account> User::getAccountById(int id) {
    for (int ident: m_accounts)
        if (ident == id)
            return BankController::getInstance()->getAccountById(id);
    return weak_ptr<Account>();
}

void User::addAccount(int ID) {
    m_accounts.emplace_back(ID);
}

void User::removeAccount(const int id) {
    BankController *bc = BankController::getInstance();
    for (int i = 0; i < m_accounts.size(); i++) {
        shared_ptr<Account> p = bc->getAccountById(m_accounts[i]).lock();
        if (p->ID == id) {
            bc->removeAccount(id);
            m_accounts.erase(m_accounts.begin() + i);
            break;
        }
    }
}

string User::serialize() {
    string acc = "";
    BankController * bc = BankController::getInstance();
    for (int id: m_accounts) {
        acc += to_string(id) + ",";
    }
    if (acc.length() != 0)
      acc[acc.length() - 1] = 0;
    string res = m_name + "," + m_pwd + "," + acc;
    return res;
}

unique_ptr<User> User::unserialize(string serializedObj) {
    vector<string> str = split(serializedObj, ',');

    string name = str[0];
    string pwd = str[1];
    int IDs[str.size() - 2];
    for (int i = 0; i < str.size() - 2; i++)
        IDs[i] = atoi(str[i + 2].c_str());

    unique_ptr<User> user = unique_ptr<User>(new User(name, pwd, 0));
    for (int id: IDs)
        user->addAccount(id);

    return user;
}