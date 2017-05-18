//
// Created by erik on 18.05.17.
//

#pragma once


#include "Account.h"

class BuildingLoanContract
        : public Account
{
public:
    static const string name = "Building Loan Contract";
    static const string description = "Lorem ipsum dolor sit amet.";

    BuildingLoanContract(User *owner, User *contact, const string &bankCode, int savingSum);
    int getSavingSum() const;
private:
    int m_savingSum;
};

