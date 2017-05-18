//
// Created by erik on 11.05.17.
//

#pragma once

#include <vector>
#include "User.h"
using namespace std;

class LoginController {
public:
    LoginController();
    ~LoginController();

    bool addUser(string name, string pwd);
    bool login(string name, string pwd);
    const string loggedInAs() const;
private:
    vector<User> * m_users;
    User * m_activeUser;
};
