//
// Created by erik on 11.05.17.
//

#ifndef PROGRAMMING_CPP_LOGINCONTROLLER_H
#define PROGRAMMING_CPP_LOGINCONTROLLER_H
#include <vector>
#include "User.h"
using namespace std;

class LoginController {
    vector<User> * m_users;
    User * m_activeUser;
public:
    LoginController();
    ~LoginController();

    void addUser(string name, string pwd);
    bool login(string name, string pwd);
    string loggedInAs();
};


#endif //PROGRAMMING_CPP_LOGINCONTROLLER_H
