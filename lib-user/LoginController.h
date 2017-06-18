//
// Created by erik on 11.05.17.
//

#pragma once

#include <vector>
#include "User.h"
#include "../Loader.h"

using namespace std;

class LoginController {
public:
    LoginController();
    ~LoginController();

    bool addUser(string name, string pwd);
    bool login(string name, string pwd);
    shared_ptr<User> loggedInAs() const;
    string serialize();

    void save();
    void load();
private:
    vector<shared_ptr<User>> m_users;
    shared_ptr<User> m_activeUser;
    Loader * m_loader;
};
