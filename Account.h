//
// Created by erik on 18.05.17.
//

#pragma once

#include <string>
#include <ctime>
#include "User.h"

using namespace std;

class Account {
public:
    static const string name = 0;
    static const string description = 0;

    const string accountNumber;
    const string bankCode;

    const User * const owner;
    const time_t inaugurationDate;

    Account(User * owner, User * contact, string bankCode);
    ~Account();
    int getBalance() const;
    double getRateOfInterest() const;
    void changeContact(User * newContact);
    const User * const  getContact() const;
protected:
    int m_balance;
    User * m_contact;
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

