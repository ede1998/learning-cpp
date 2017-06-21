//
// Created by erik on 18.05.17.
//

#pragma once


#include "Account.h"
#include <vector>
#include "../Loader.h"

class CheckAccount
        : public Account
{
public:
    static constexpr char * name = (char *) "Check Account";
    static constexpr char * description = (char *) "This is the check account and it has cool features.";

    CheckAccount(string owner, string contact, const string &bankCode, int overdraft);
    ~CheckAccount();

    string getName() override;
    string getDescription() override;

    int getOverdraft() const;

    string serialize() override;
    static unique_ptr<CheckAccount> unserialize(string serializedObj);
private:
    CheckAccount(string owner, string contact, const string &bankCode, int ID, int inaugurationDate, int overdraft);
    int m_overdraft;
};

