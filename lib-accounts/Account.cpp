//
// Created by erik on 18.05.17.
//

#include "Account.h"
#include <sstream>

int Account::nextID = 0;

Account::Account(string owner, string contact, string bankCode, AccType type)
        : ID(nextID++),
          bankCode(bankCode),
          inaugurationDate(time(0)),
          accountNumber(bankCode + to_string(ID)),
          owner(owner),
          type(type)
{
    m_contact = contact;
}

Account::Account(string owner, string contact, string bankCode, int ID, int inaugurationDate, AccType type)
        : ID(ID),
          bankCode(bankCode),
          inaugurationDate(inaugurationDate),
          accountNumber(bankCode + to_string(ID)),
          owner(owner),
          type(type)
{
    m_contact = contact;
    if (ID >= nextID) nextID = ID+1;
}

int Account::getBalance() const {
    return m_balance;
}

void Account::setBalance(int balance) {
    m_balance = balance;
}
void Account::setRateOfInterest(double roi) {
    m_rateOfInterest = roi;
}

double Account::getRateOfInterest() const {
    return m_rateOfInterest;
}

void Account::changeContact(string newContact) {
    m_contact = newContact;
}

string Account::getContact() const {
    return m_contact;
}

Account::~Account() {

}

string Account::accountSerialize() {
    return to_string(type) + "," + to_string(ID) + "," + accountNumber + "," + bankCode + "," + owner + "," + to_string(inaugurationDate) + "," +
            m_contact + "," + to_string(m_balance) + "," + to_string(m_rateOfInterest);
}
