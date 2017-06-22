//
// Created by erik on 01.06.17.
//

#pragma once

#include "../Loader.h"
#include "../lib-user/LoginController.h"
#include "Account.h"

class BankController {
public:
    static BankController * getInstance();
    ~BankController();
    weak_ptr<Account> getAccountByIndex(const int index) const;
    weak_ptr<Account> getAccountById(const int id) const;
    int createCheckAccount(string owner, string contact, const string &bankCode,
                                         int overdraft);
    int createBuildingLoanContract(string owner, string contact,
                                                 const string &bankCode, int savingSum);
    int createInstantAccessSavingsAccount(string owner, string contact,
                                                        const string &bankCode, int minimumTerm);
    void removeAccount(const int id);



    void save();
    void load();
private:
    BankController();

    string serialize();
    void unserialize(string serializedObj);

    static BankController * s_instance;
    vector<shared_ptr<Account>> m_accounts;
    Loader * m_loader;
};

