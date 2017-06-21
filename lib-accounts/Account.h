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

    const string owner;
    const time_t inaugurationDate;

    ~Account();

    virtual string getName() = 0;
    virtual string getDescription() = 0;
    int getBalance() const;
    void setBalance(int balance);
    double getRateOfInterest() const;
    void setRateOfInterest(double roi);
    void changeContact(string newContact);
    string getContact() const;
    virtual string serialize() = 0;
    //static unique_ptr<Account> unserialize(string serializedObj) = 0; //TODO is it possible?
protected:
    Account(string owner, string contact, string bankCode, AccType type);
    Account(string owner, string contact, string bankCode, int ID, int inaugurationDate, AccType type);
    int m_balance;
    string m_contact;
    double m_rateOfInterest;
    void * m_transactions; //Struct with date, dest, src,... //TODO optional
    string accountSerialize();
private:
    static int nextID;
};

