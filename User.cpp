//
// Created by erik on 11.05.17.
//

#include "User.h"

User::User(const string &m_name, const string &pwd) : m_name(m_name) {
    hash<string> hashedPwd = hash<string>();
    m_pwd = hashedPwd(pwd);
}

User::~User() {
}

bool User::isCorrectPassword(string pwd) {
    hash<string> hashedPwd = hash<string>();
    string test;
    test = hashedPwd(pwd);
    return  test == m_pwd;
}

string User::getName() {
    return m_name;
}
