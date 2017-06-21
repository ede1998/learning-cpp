//
// Created by erik on 18.05.17.
//

#pragma once

#include "Account.h"
#include "../Loader.h"

class InstantAccessSavingsAccount
        : public Account
{
public:
    static constexpr char * name = (char *) "Instant Access Savings Account";
    static constexpr char * description = (char *) "Get paid.";

    InstantAccessSavingsAccount(string owner, string contact, const string &bankCode, int minimumTerm);
    ~InstantAccessSavingsAccount();


    string getName() override;
    string getDescription() override;
    int getMinimumTerm() const;

    string serialize() override;
    static unique_ptr<InstantAccessSavingsAccount> unserialize(string serializedObj);
private:
    InstantAccessSavingsAccount(string owner, string contact, const string &bankCode, int ID, int inaugurationDate, int minimumTerm);
    const int m_minimumTerm;
};

