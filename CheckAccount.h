//
// Created by erik on 18.05.17.
//

#pragma once


#include "Account.h"

class CheckAccount
        : public Account
{
public:
    static const string name = "Check Account";
    static const string description = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr,"
            " sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, "
            "sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita"
            " kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum "
            "dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut"
            " labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo"
            " duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est "
            "Lorem ipsum dolor sit amet.";

    CheckAccount(User *owner, User *contact, const string &bankCode, int overdraft);

    int getOverdraft() const;
private:
    int m_overdraft;
};

