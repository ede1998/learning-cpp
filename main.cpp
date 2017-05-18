#include <iostream>
#include "LoginController.h"

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
    LoginController * lc = new LoginController();
    int option = -1;
    string name, pwd;
    while (option != 0) {
        cout << "Do you want to login(0) or create a new account(1)?" << endl;
        cin >> option;
        if (option == 1) {
            //Create account
            cout << "Please enter name and password." << endl;
            cin >> name;
            cin >> pwd;
            lc->addUser(name, pwd);
        }
    }
    //login
    do {
    cout << "Please enter login credentials." << endl;
    cin >> name;
    cin >> pwd;}
    while (!lc->login(name, pwd));
    cout << "Successfully logged in as user " << lc->loggedInAs() << endl;
    return 0;
}