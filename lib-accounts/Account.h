//
// Created by erik on 18.05.17.
//

#pragma once

#include <string>
#include <ctime>
#include <memory>
#include "../lib-user/User.h"

using namespace std;

enum AccType {IASA, BLC, CA};

class User;

class Account {
public:
    const string accountNumber;
    const string bankCode;
    const int ID;
    const AccType type;

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
    virtual string serialize() = 0;
protected:
    Account(shared_ptr<User> owner, shared_ptr<User> contact, string bankCode, AccType type);
    Account(string serializedObj);
    int m_balance;
    shared_ptr<User> m_contact;
    double m_rateOfInterest;
    void * m_transactions; //Struct with date, dest, src,...
    string accountSerialize();
    void accountUnserialize(string serializedObj);
private:
    static int nextID;

    /*
    v. Einen Besitzer (erst einmal ein Name / ein Nutzer der einsehbar ist / ein
            Nutzer, der einsehbar & verwaltbar ist)
    x. Eine Liste an getätigten Transaktionen
    */
};

