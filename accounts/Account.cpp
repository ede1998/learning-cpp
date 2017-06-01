//
// Created by erik on 18.05.17.
//

#include "Account.h"

int Account::nextID = 0;

Account::Account(shared_ptr<User> owner, shared_ptr<User> contact, string bankCode)
        : ID(nextID++),
          bankCode(bankCode),
          inaugurationDate(time(0)),
          accountNumber(bankCode + to_string(ID) + to_string(random())),
          owner(owner)
{
    m_contact = contact;
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


