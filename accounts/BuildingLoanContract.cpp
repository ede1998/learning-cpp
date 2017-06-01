//
// Created by erik on 18.05.17.
//

#include "BuildingLoanContract.h"

BuildingLoanContract::BuildingLoanContract(shared_ptr<User> owner, shared_ptr<User> contact, const string &bankCode,
                                           int savingSum)
        : Account(owner, contact, bankCode)
{
    m_savingSum = savingSum;
}

int BuildingLoanContract::getSavingSum() const {
    return m_savingSum;
}

BuildingLoanContract::~BuildingLoanContract() {

}

string BuildingLoanContract::getDescription() {
    return description;
}

string BuildingLoanContract::getName() {
    return name;
}


