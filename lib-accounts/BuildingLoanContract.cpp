//
// Created by erik on 18.05.17.
//

#include "BuildingLoanContract.h"

BuildingLoanContract::BuildingLoanContract(string owner, string contact, const string &bankCode,
                                           int savingSum)
        : Account(owner, contact, bankCode, BLC)
{
    m_savingSum = savingSum;
}

BuildingLoanContract::BuildingLoanContract(string owner, string contact, const string &bankCode,
                                           int ID, int inaugurationDate, int savingSum)
        : Account(owner, contact, bankCode, ID, inaugurationDate, BLC)
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
string BuildingLoanContract::serialize() {
    return accountSerialize() + "," + to_string(m_savingSum);
}

unique_ptr<BuildingLoanContract> BuildingLoanContract::unserialize(string serializedObj) {
    vector<string> str = split(serializedObj, ',');
    //format: 0type, 1ID, 2accountNumber, 3bankCode, 4owner, 5inaugurationDate,
    // 6m_contact, 7m_balance, 8m_rateOfInterest, 9m_savingSum
    //constructor: owner, contact, bankCode, ID, inaugurationDate, savingSum
    string owner = str[4];
    string contact = str[6];
    string bankCode = str[3];
    int ID = atoi(str[1].c_str());
    int inaugurationDate = atoi(str[5].c_str());
    int savingSum = atoi(str[9].c_str());
    return unique_ptr<BuildingLoanContract>(new BuildingLoanContract(owner, contact, bankCode, ID, inaugurationDate, savingSum));
}
