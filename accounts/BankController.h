//
// Created by erik on 01.06.17.
//

#pragma once


#include "Account.h"

class BankController {
public:
    BankController();
    ~BankController();
    weak_ptr<Account> getAccount(int index) const;
    weak_ptr<Account> createCheckAccount(shared_ptr<User> owner, shared_ptr<User> contact, const string &bankCode,
                                         int overdraft);
    weak_ptr<Account> createBuildingLoanContract(shared_ptr<User> owner, shared_ptr<User> contact,
                                                 const string &bankCode, int savingSum);
    weak_ptr<Account> createInstantAccessSavingsAccount(shared_ptr<User> owner, shared_ptr<User> contact,
                                                        const string &bankCode, int minimumTerm);
private:
    vector<shared_ptr<Account>> m_accounts;
};

