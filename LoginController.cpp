//
// Created by erik on 11.05.17.
//

#include "LoginController.h"

/**
 * Constructor of LoginController. Creates a new instance of LoginController.
 */
LoginController::LoginController() {
    m_users = new vector<User>();
}

/**
 * Destructor of LoginController. Destroys an instance of LoginController.
 */
LoginController::~LoginController() {
    delete m_users;
}

/**
 * Adds new user for LoginController.
 * @param name Username
 * @param pwd Password for the user
 * @return True if new user was added successfully, false otherwise
 */
bool LoginController::addUser(string name, string pwd) {
    for (int i = 0; i < m_users->size(); i++) {
        if ((*m_users)[i].getName() == name) {
            return false;
        }
    }
    m_users->emplace_back(User(name, pwd));
        return true;
}

/**
 * Returns the username of the logged in user. If no user is logged in, nullptr is returned.
 * @return username of logged in user or nullptr if no user is logged in
 */
const string LoginController::loggedInAs() const {
    if (m_activeUser == nullptr)
        return nullptr;
    return m_activeUser->getName();
}

/**
 * Login with username name using pwd as password. The username-password-combination must first be
 * registered via LoginController::addUser() to be accepted by this function. The function goes through
 * all registered users and looks for matching user names. Then compares passwords.
 * @param name username used to login
 * @param pwd password used to login
 * @return True on success, false if no matching user-password combination was found
 */
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
