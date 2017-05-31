#include <iostream>
#include "user/LoginController.h"
#include "Menu.h"

using namespace std;

/**
 * Main function. Creates a LoginController class and asks to login or create new account.
 * Then asks for username and password. When creating an account, it asks again afterwards
 * whether to login or create a new account. When logging in, it forces another try if input
 * did not match a valid username-pwd-combination. Otherwise print "logged in as " + user and
 * then terminates with return-code 0.
 * @return 0 on success.
 */
int main() {
    Menu * m = new Menu();
    while (m->main()) {}
    delete m;
    return 0;
}