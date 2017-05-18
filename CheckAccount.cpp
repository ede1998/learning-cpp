//
// Created by erik on 18.05.17.
//

#include "CheckAccount.h"

CheckAccount::CheckAccount(User *owner, User *contact, const string &bankCode, int overdraft)
        : Account(owner, contact, bankCode)
{
    m_overdraft = overdraft;
}

int CheckAccount::getOverdraft() const {
    return m_overdraft;
}