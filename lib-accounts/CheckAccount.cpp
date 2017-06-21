//
// Created by erik on 18.05.17.
//

#include "CheckAccount.h"

CheckAccount::CheckAccount(string owner, string contact, const string &bankCode, int overdraft)
        : Account(owner, contact, bankCode, CA)
{
    m_overdraft = overdraft;
}

CheckAccount::CheckAccount(string owner, string contact, const string &bankCode,
                           int ID, int inaugurationDate, int overdraft)
        : Account(owner, contact, bankCode, ID, inaugurationDate, CA)
{
    m_overdraft = overdraft;
}

int CheckAccount::getOverdraft() const {
    return m_overdraft;
}

CheckAccount::~CheckAccount() {

}

string CheckAccount::getName() {
    return name;

}

string CheckAccount::getDescription() {
    return description;
}

string CheckAccount::serialize() {
    return accountSerialize() + "," + to_string(m_overdraft);
}

unique_ptr<CheckAccount> CheckAccount::unserialize(string serializedObj) {
    vector<string> str = split(serializedObj, ',');
    string owner = str[4];
    string contact = str[6];
    string bankCode = str[3];
    int ID = atoi(str[1].c_str());
    int inaugurationDate = atoi(str[5].c_str());
    int overdraft = atoi(str[9].c_str());
    return unique_ptr<CheckAccount>(new CheckAccount(owner, contact, bankCode, ID, inaugurationDate, overdraft));
}