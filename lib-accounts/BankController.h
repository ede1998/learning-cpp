//
// Created by erik on 01.06.17.
//

#pragma once


#include "Account.h"

class BankController {
public:
    BankController();
    ~BankController();
    weak_ptr<Account> getAccount(const int index) const;
    weak_ptr<Account> createCheckAccount(shared_ptr<User> owner, shared_ptr<User> contact, const string &bankCode,
                                         int overdraft);
    weak_ptr<Account> createBuildingLoanContract(shared_ptr<User> owner, shared_ptr<User> contact,
                                                 const string &bankCode, int savingSum);
    weak_ptr<Account> createInstantAccessSavingsAccount(shared_ptr<User> owner, shared_ptr<User> contact,
                                                        const string &bankCode, int minimumTerm);
    void deleteAccount(const int index);

    string serialize();
    void unserialize(string serializedObj);

    void save();
    void load();
private:
    vector<shared_ptr<Account>> m_accounts;
    Loader * m_loader;
};

