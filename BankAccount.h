#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <bits/stdc++.h>
#include <iostream>
#include <Client.h>
using namespace std;

class BankAccount
{
    public:
        BankAccount();
        BankAccount(double input_Balance);
        void setBalance(double input_Balance);
        void setId(string input_Id);
        string getId();
        double getBalance();
        void withdraw(double withdraw_value,int Bindex);
        void deposit (double deposit_value,int Bindex);
        void fill_file();
        virtual ~BankAccount();

    protected:
        string AccountId;
        double Balance;

    private:


};

#endif // BANKACCOUNT_H
