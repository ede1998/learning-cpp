//
// Created by erik on 18.05.17.
//

#pragma once

#include "Account.h"

class BuildingLoanContract
        : public Account
{
public:
    static constexpr char * name = "Building Loan Contract";
    static constexpr char * description = "Build a house.";

    BuildingLoanContract(User *owner, User *contact, const string &bankCode, int savingSum);
    ~BuildingLoanContract();
    int getSavingSum() const;
private:
    int m_savingSum;
};

