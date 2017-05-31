//
// Created by erik on 18.05.17.
//

#pragma once


#include "Account.h"

class CheckAccount
        : public Account
{
public:
    static constexpr char * name = "Check Account";
    static constexpr char * description = "This is the check account and it has cool features.";

    CheckAccount(User *owner, User *contact, const string &bankCode, int overdraft);
    ~CheckAccount();

    int getOverdraft() const;
private:
    int m_overdraft;
};

