//
// Created by erik on 18.05.17.
//

#pragma once

#include "Account.h"

class InstantAccessSavingsAccount
        : public Account
{
public:
    static constexpr char * name = (char *) "Instant Access Savings Account";
    static constexpr char * description = (char *) "Get paid.";

    InstantAccessSavingsAccount(shared_ptr<User>owner, shared_ptr<User>contact, const string &bankCode, int minimumTerm);
    ~InstantAccessSavingsAccount();


    string getName() override;
    string getDescription() override;
    int getMinimumTerm() const;

    string serialize() override;
private:
    const int m_minimumTerm;
};

