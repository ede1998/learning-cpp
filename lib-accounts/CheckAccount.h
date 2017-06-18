//
// Created by erik on 18.05.17.
//

#pragma once


#include "Account.h"

class CheckAccount
        : public Account
{
public:
    static constexpr char * name = (char *) "Check Account";
    static constexpr char * description = (char *) "This is the check account and it has cool features.";

    CheckAccount(shared_ptr<User> owner, shared_ptr<User> contact, const string &bankCode, int overdraft);
    ~CheckAccount();

    string getName() override;
    string getDescription() override;

    int getOverdraft() const;

    string serialize() override;
private:
    int m_overdraft;
};

