//
// Created by erik on 18.05.17.
//

#include "InstantAccessSavingsAccount.h"

InstantAccessSavingsAccount::InstantAccessSavingsAccount(string owner, string contact,
                                                         const string &bankCode, int minimumTerm)
        : Account(owner, contact, bankCode, IASA),
          m_minimumTerm(minimumTerm)
{

}

InstantAccessSavingsAccount::InstantAccessSavingsAccount(string owner, string contact, const string &bankCode,
                                                         int ID, int inaugurationDate, int minimumTerm)
        : Account(owner, contact, bankCode, ID, inaugurationDate, IASA),
          m_minimumTerm(minimumTerm)
{

}

int InstantAccessSavingsAccount::getMinimumTerm() const {
    return m_minimumTerm;
}

InstantAccessSavingsAccount::~InstantAccessSavingsAccount() {

}

string InstantAccessSavingsAccount::getName() {
    return name;
}

string InstantAccessSavingsAccount::getDescription() {
    return description;
}

string InstantAccessSavingsAccount::serialize() {
    return accountSerialize() + "," + to_string(m_minimumTerm);
}

unique_ptr<InstantAccessSavingsAccount> InstantAccessSavingsAccount::unserialize(string serializedObj) {
    vector<string> str = split(serializedObj, ',');
    string owner = str[4];
    string contact = str[6];
    string bankCode = str[3];
    int ID = atoi(str[1].c_str());
    int inaugurationDate = atoi(str[5].c_str());
    int minimumTerm = atoi(str[9].c_str());
    return unique_ptr<InstantAccessSavingsAccount>(new InstantAccessSavingsAccount(owner, contact, bankCode, ID, inaugurationDate, minimumTerm));
}