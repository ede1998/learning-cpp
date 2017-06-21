//
// Created by erik on 11.05.17.
//

#include "User.h"
#include "../lib-accounts/BankController.h"

/**
 * Constructor of class User. Creates a new User and takes a username and a password as parameter.
 * Only a hash of the password is stored.
 * @param m_name Username
 * @param pwd Password for the user
 */
User::User(const string &m_name, const string &pwd) : m_name(m_name) {
    hash<string> hashedPwd = hash<string>();
    m_pwd = hashedPwd(pwd);
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
    hash<string> hashedPwd = hash<string>();
    string test;
    test = hashedPwd(pwd);
    return  test == m_pwd;
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
            return BankController::getInstance().getAccountById(id);
    return weak_ptr<Account>();
}

void User::addAccount(int ID) {
    m_accounts.emplace_back(ID);
}

void User::removeAccount(const int id) {


    m_accounts.erase(m_accounts.begin() + index);
}

string User::serialize() {
    string acc = "";
    BankController & bc = BankController::getInstance();
    for (int id: m_accounts) {
        shared_ptr<Account> as = bc.getAccountById(id).lock();
        acc += as->ID + ",";
    }
    if (acc.length() != 0)
      acc[acc.length() - 1] = 0;
    return m_name + "," + m_pwd + "," + acc;
}

unique_ptr<User> User::unserialize(string serializedObj) {
    vector<string> str = split(serializedObj, ',');

    string name = str[0];
    string pwd = str[1];
    int IDs[str.size() - 3];
    for (int i = 0; i < str.size() - 2; i++)
        IDs[i] = atoi(str[i + 2].c_str());

    unique_ptr<User> user = unique_ptr<User>(new User(name, pwd, 0));
    for (int id: IDs)
        user->addAccount(id);

    return user;
}