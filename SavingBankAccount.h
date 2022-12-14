#ifndef SAVINGBANKACCOUNT_H
#define SAVINGBANKACCOUNT_H

#include "BankAccount.h"

class SavingBankAccount : public BankAccount
{
    public:
        SavingBankAccount();
        SavingBankAccount(double input_Balance);
        void setminimumBalance(double input_minimumBalance);
        double getminimumBalance();
        void withdraw(double withdraw_value, int Bindex);
        void deposit (double deposit_value, int Bindex);
        void fill_file();
        virtual ~SavingBankAccount();

    protected:

    private:
        double minimumBalance;

};

#endif // SAVINGBANKACCOUNT_H
