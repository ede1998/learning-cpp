//
// Created by erik on 01.06.17.
//

#include "BankController.h"
#include "CheckAccount.h"
#include "BuildingLoanContract.h"
#include "InstantAccessSavingsAccount.h"


BankController * BankController::getInstance() {
    if (m_self == nullptr)
        m_self = new BankController();
    return m_self;
}
BankController::BankController()
{
    m_loader = new Loader("Accounts.csv");
}

BankController::~BankController() {
    delete m_loader;
    m_loader = nullptr;
}

int BankController::createCheckAccount(string owner, string contact,
                                                     const string &bankCode, int overdraft) {
    m_accounts.emplace_back(new CheckAccount(owner, contact, bankCode, overdraft));
    return m_accounts.back()->ID;
}

int BankController::createBuildingLoanContract(string owner, string contact,
                                                             const string &bankCode, int savingSum) {
    m_accounts.emplace_back(new BuildingLoanContract(owner, contact, bankCode, savingSum));
    return m_accounts.back()->ID;
}

int BankController::createInstantAccessSavingsAccount(string owner, string contact,
                                                                    const string &bankCode, int minimumTerm) {
    m_accounts.emplace_back(new InstantAccessSavingsAccount(owner, contact, bankCode, minimumTerm));
    return m_accounts.back()->ID;
}

weak_ptr<Account> BankController::getAccountByIndex(const int index) const {
    return m_accounts.at(index);
}

weak_ptr<Account> BankController::getAccountById(const int id) const {
    for (int i = 0; i < m_accounts.size(); i++) {
        if (m_accounts[i]->ID == id)
            return m_accounts[i];
    }
    return weak_ptr<Account>();
}

void BankController::removeAccount(const int id) {
    for (int i = 0; i < m_accounts.size(); i++) {
        if (m_accounts[i]->ID == id)
            m_accounts.erase(m_accounts.begin() + i);
        break;
    }
}

string BankController::serialize() {
    string str = "";
    for (shared_ptr<Account> a: m_accounts) {
       str += a->serialize() + "\n";
    }
    return str;
}

void BankController::unserialize(string serializedObj) {
    vector<string> acc = split(serializedObj, '\n');
    for (string str: acc) {
        switch (atoi(split(str, ',')[0].c_str())) {
            case CA:
                m_accounts.emplace_back(CheckAccount::unserialize(str));
                break;
            case BLC:
                m_accounts.emplace_back(BuildingLoanContract::unserialize(str));
                break;
            case IASA:
                m_accounts.emplace_back(InstantAccessSavingsAccount::unserialize(str));
                break;
        }
    }
}

void BankController::load() {
    unserialize(m_loader->load());
}

void BankController::save() {
    m_loader->save(serialize());
}