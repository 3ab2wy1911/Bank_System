#ifndef BANKAPPLICATION_H
#define BANKAPPLICATION_H
#include "BankAccount.h"
#include "SavingBankAccount.h"
#include "Client.h"

class BankApplication
{
    public:
        BankApplication();
        void menu();
        virtual ~BankApplication();

    protected:
        Client newclient;
        BankAccount newbank;

    private:

};

#endif // BANKAPPLICATION_H
