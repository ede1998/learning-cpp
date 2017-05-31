//
// Created by erik on 18.05.17.
//

#pragma once

#include "Account.h"

class InstantAccessSavingsAccount
        : public Account
{
public:
    static constexpr char * name = "Instant Access Savings Account";
    static constexpr char * description = "Get paid.";
    InstantAccessSavingsAccount(User *owner, User *contact, const string &bankCode, int minimumTerm);
    ~InstantAccessSavingsAccount();

    int getMinimumTerm() const;
private:
    const int m_minimumTerm;
};

