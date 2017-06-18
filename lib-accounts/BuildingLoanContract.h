//
// Created by erik on 18.05.17.
//

#pragma once

#include "Account.h"

class BuildingLoanContract
        : public Account
{
public:
    static constexpr char * name = (char *) "Building Loan Contract";
    static constexpr char * description = (char *) "Build a house.";

    BuildingLoanContract(shared_ptr<User> owner, shared_ptr<User> contact, const string &bankCode, int savingSum);
    ~BuildingLoanContract();

    string getName() override;

    string getDescription() override;

    int getSavingSum() const;

    string serialize() override;
    static unique_ptr<BuildingLoanContract> unserialize(string serializedObj);
private:
    int m_savingSum;
};

