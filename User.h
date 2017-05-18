//
// Created by erik on 11.05.17.
//

#ifndef PROGRAMMING_CPP_USER_H
#define PROGRAMMING_CPP_USER_H

#include <string>
#include <unistd.h>
using namespace std;

class User {
    string m_name;
    string m_pwd;
public:
    User(const string &m_name, const string &pwd);
    ~User();
    string getName();
    bool isCorrectPassword(string pwd);
};


#endif //PROGRAMMING_CPP_USER_H
