//
// Created by erik on 18.05.17.
//

#pragma once

#include <string>
#include <ctime>
#include <memory>
#include "../lib-user/User.h"

using namespace std;

class User;

class Account {
public:
    const string accountNumber;
    const string bankCode;

    static constexpr char * name = (char *) "";
    static constexpr char * description = (char *) "";

    shared_ptr<User> const owner;
    const time_t inaugurationDate;

    ~Account();

    virtual string getName() = 0;
    virtual string getDescription() = 0;
    int getBalance() const;
    double getRateOfInterest() const;
    void changeContact(shared_ptr<User> newContact);
    const shared_ptr<const User> getContact() const;
protected:
    Account(shared_ptr<User> owner, shared_ptr<User> contact, string bankCode);
    int m_balance;
    shared_ptr<User> m_contact;
    const int ID;
    double m_rateOfInterest;
    void * m_transactions; //Struct with date, dest, src,...
private:
    static int nextID;

    /*
    v. Einen Besitzer (erst einmal ein Name / ein Nutzer der einsehbar ist / ein
            Nutzer, der einsehbar & verwaltbar ist)
    x. Eine Liste an getätigten Transaktionen
    */
};

