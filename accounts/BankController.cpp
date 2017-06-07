//
// Created by erik on 01.06.17.
//

#include "BankController.h"
#include "CheckAccount.h"
#include "BuildingLoanContract.h"
#include "InstantAccessSavingsAccount.h"

BankController::BankController() {

}

BankController::~BankController() {

}

weak_ptr<Account> BankController::createCheckAccount(shared_ptr<User> owner, shared_ptr<User> contact,
                                                     const string &bankCode, int overdraft) {
    m_accounts.emplace_back(new CheckAccount(owner, contact, bankCode, overdraft));
    return m_accounts.back();
}

weak_ptr<Account> BankController::createBuildingLoanContract(shared_ptr<User> owner, shared_ptr<User> contact,
                                                             const string &bankCode, int savingSum) {
    m_accounts.emplace_back(new BuildingLoanContract(owner, contact, bankCode, savingSum));
    return m_accounts.back();
}

weak_ptr<Account> BankController::createInstantAccessSavingsAccount(shared_ptr<User> owner, shared_ptr<User> contact,
                                                                    const string &bankCode, int minimumTerm) {
    m_accounts.emplace_back(new InstantAccessSavingsAccount(owner, contact, bankCode, minimumTerm));
    return m_accounts.back();
}

weak_ptr<Account> BankController::getAccount(const int index) const {
    return m_accounts.at(index);
}

void BankController::deleteAccount(const int index) {
    if ((index < 0) || (index >= m_accounts.size())) return;
    m_accounts.at(index)->owner->removeAccount(index);
    m_accounts.erase(m_accounts.begin() + index);
}


