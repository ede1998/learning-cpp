//
// Created by erik on 01.06.17.
//

#pragma once

#include "../Loader.h"
#include "../lib-user/LoginController.h"
#include "Account.h"

class BankController {
public:
    static BankController & getInstance();
    ~BankController();
    weak_ptr<Account> getAccountByIndex(const int index) const;
    weak_ptr<Account> getAccountById(const int id) const;
    weak_ptr<Account> createCheckAccount(string owner, string contact, const string &bankCode,
                                         int overdraft);
    weak_ptr<Account> createBuildingLoanContract(string owner, string contact,
                                                 const string &bankCode, int savingSum);
    weak_ptr<Account> createInstantAccessSavingsAccount(string owner, string contact,
                                                        const string &bankCode, int minimumTerm);
    void deleteAccount(const int index);

    string serialize();
    void unserialize(string serializedObj);

    void save();
    void load();
private:
    BankController();
    static BankController m_self;
    vector<shared_ptr<Account>> m_accounts;
    Loader * m_loader;
};

