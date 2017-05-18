//
// Created by erik on 11.05.17.
//

#include "LoginController.h"

LoginController::LoginController() {
    m_users = new vector<User>();
}

LoginController::~LoginController() {
    delete m_users;
}

void LoginController::addUser(string name, string pwd) {
    m_users->emplace_back(User(name, pwd));
}

string LoginController::loggedInAs() {
    if (m_activeUser == nullptr)
        return nullptr;
    return m_activeUser->getName();
}

bool LoginController::login(string name, string pwd) {
    for (int i = 0; i < m_users->size(); i++) {
        if (((*m_users)[i].getName() == name) &&
                ((*m_users)[i].isCorrectPassword(pwd))) {
            m_activeUser = &(*m_users)[i];
            return true;
        }
    }
    return false;
}
