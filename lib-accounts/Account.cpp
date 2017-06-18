//
// Created by erik on 18.05.17.
//

#include "Account.h"
#include <sstream>

int Account::nextID = 0;

Account::Account(shared_ptr<User> owner, shared_ptr<User> contact, string bankCode, AccType type)
        : ID(nextID++),
          bankCode(bankCode),
          inaugurationDate(time(0)),
          accountNumber(bankCode + to_string(ID) + to_string(random())),
          owner(owner),
          type(type)
{
    m_contact = contact;
}

Account::Account(string serializedObj)
        : accountUnserialize(serializedObj)
{

}
int Account::getBalance() const {
    return m_balance;
}

double Account::getRateOfInterest() const {
    return m_rateOfInterest;
}

void Account::changeContact(shared_ptr<User> newContact) {
    m_contact = newContact;
}

const shared_ptr<const User> Account::getContact() const {
    return m_contact;
}

Account::~Account() {

}

string Account::accountSerialize() {
    string nowner = "";
    string ncontact = "";
    if (owner != nullptr)
        nowner = owner->getName();
    if (m_contact != nullptr)
        ncontact = m_contact->getName();
    return to_string(type) + "," + to_string(ID) + "," + accountNumber + "," + bankCode + "," + nowner + "," + to_string(inaugurationDate) + "," +
            ncontact + "," + to_string(m_balance) + "," + to_string(m_rateOfInterest);
}

void Account::accountUnserialize(string serializedObj) {
    vector<string> columns = split(serializedObj, ',');
    ID = atoi(columns[0]);

}
