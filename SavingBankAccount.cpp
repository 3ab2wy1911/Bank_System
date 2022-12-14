#include "SavingBankAccount.h"

SavingBankAccount::SavingBankAccount()
{
    minimumBalance=1000;
    Balance += minimumBalance;
}
//=========================================================================================
SavingBankAccount :: SavingBankAccount (double input_Balance)
{
    minimumBalance = 1000;
    Balance=input_Balance;
}
//=========================================================================================
void SavingBankAccount :: setminimumBalance(double input_minimumBalance)
{
    minimumBalance = input_minimumBalance;
}
//=========================================================================================
double SavingBankAccount :: getminimumBalance()
{
    return minimumBalance;
}
//==============================================================
void SavingBankAccount :: withdraw(double withdraw_value , int Bindex)
{
     ifstream file;
    ofstream target;
    vector<string>text;
    char line[100];
    file.open ("BankSystem.txt",ios::app);
     while (!file.eof())
    {
        file.getline(line, 100, '\n');
        text.push_back(string(line));
    }
    file.close();
    Balance=stod(text[Bindex]);
    AccountId = (text[Bindex-2]);
    if(withdraw_value>= minimumBalance and withdraw_value <= Balance)
        {
           Balance-=withdraw_value;
            text[Bindex]=to_string(Balance);
            target.open("BankSystem.txt");
            for(int i=0 ;i< text.size();i++ )
            {
                target<<text[i];
                target<<'\n';
            }
            target.close();
            cout <<"Thank You :) \n";
            cout<<"Account ID: "<<AccountId<<'\n';
            cout<<"Account Balance: "<<Balance<<'\n';
        }
    else if (withdraw_value<minimumBalance)
        {
            cout<<"Sorry. This is less than what you can withdraw :( \n";
        }
    else
        {
            cout<<"Sorry. This is more than what you can withdraw :( \n";
        }
}
//==============================================================
void SavingBankAccount :: deposit(double deposit_value,int Bindex)
{
     ifstream file;
    ofstream target;
    vector<string>text;
    char line[100];
    file.open ("BankSystem.txt",ios::app);
     while (!file.eof())
    {
        file.getline(line, 100, '\n');
        text.push_back(string(line));
    }
    file.close();
    Balance=stod(text[Bindex]);
    AccountId = (text[Bindex-2]);
    if(deposit_value >= 100)
    {
        Balance+=deposit_value;
         text[Bindex]=to_string(Balance);
            target.open("BankSystem.txt");
            for(int i=0 ;i< text.size();i++ )
            {
                target<<text[i];
                target<<'\n';
            }
            target.close();
        cout <<"Thank You :) \n";
        cout<<"Account ID: "<<AccountId<<'\n';
        cout<<"Account Balance: "<<Balance<<'\n';
    }
    else
        cout<<"Sorry, you can't deposit a value less than 100 :( \n";
}
//=========================================================================================
void SavingBankAccount :: fill_file()
  {
    ofstream file;
    file.open("BankSystem.txt",ios:: app);
    if (file.is_open())
    {
    file << "Saving" << endl;
    file << to_string(Balance) <<endl;
    file << "________________________________________________________"<<endl;
    }

    file.close();
  }
//=========================================================================================
SavingBankAccount::~SavingBankAccount()
{
}
