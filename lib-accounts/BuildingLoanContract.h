//
// Created by erik on 18.05.17.
//

#pragma once

#include "Account.h"
#include "../Loader.h"

class BuildingLoanContract
        : public Account
{
public:
    static constexpr char * name = (char *) "Building Loan Contract";
    static constexpr char * description = (char *) "Build a house.";

    BuildingLoanContract(string owner, string contact, const string &bankCode, int savingSum);
    ~BuildingLoanContract();

    string getName() override;

    string getDescription() override;

    int getSavingSum() const;

    string serialize() override;
    static unique_ptr<BuildingLoanContract> unserialize(string serializedObj);
private:
    BuildingLoanContract(string owner, string contact, const string &bankCode, int ID, int inaugurationDate, int savingSum);
    int m_savingSum;
};

