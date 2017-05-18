//
// Created by erik on 11.05.17.
//

#include "User.h"

/**
 * Constructor of class User. Creates a new User and takes a username and a password as parameter.
 * Only a hash of the password is stored.
 * @param m_name Username
 * @param pwd Password for the user
 */
User::User(const string &m_name, const string &pwd) : m_name(m_name) {
    hash<string> hashedPwd = hash<string>();
    m_pwd = hashedPwd(pwd);
    m_accounts = new vector<Account>();
}

User::~User() {
    delete m_accounts;
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
