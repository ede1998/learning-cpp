//
// Created by erik on 18.05.17.
//

#include "InstantAccessSavingsAccount.h"

InstantAccessSavingsAccount::InstantAccessSavingsAccount(User *owner, User *contact, const string &bankCode, int minimumTerm)
        : Account(owner, contact, bankCode),
          m_minimumTerm(minimumTerm)
{

}

int InstantAccessSavingsAccount::getMinimumTerm() const {
    return m_minimumTerm;
}

InstantAccessSavingsAccount::~InstantAccessSavingsAccount() {

}
