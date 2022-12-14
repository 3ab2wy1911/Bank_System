#include "BankAccount.h"

BankAccount::BankAccount()
{
}
//==============================================================
BankAccount::BankAccount(double input_Balance)
{
    Balance = input_Balance;
}
//==============================================================
void BankAccount :: setBalance(double input_Balance)
{
    Balance = input_Balance;
}
//==============================================================
void BankAccount :: setId(string input_Id)
{
    AccountId = input_Id;
}
//==============================================================
string BankAccount :: getId()
{
    return AccountId;
}
//==============================================================
double BankAccount :: getBalance()
{
    return Balance;
}
//==============================================================
void BankAccount :: withdraw(double withdraw_value,int Bindex)
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
    if(withdraw_value<= Balance)
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
    else
        cout<<"Sorry. This is more than what you can withdraw :( \n";
}
//==============================================================
void BankAccount :: deposit(double deposit_value , int Bindex)
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
    if (deposit_value>0)
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
    else cout<<"Invalid Value :( \n";
}
//==============================================================
void BankAccount :: fill_file()
  {
    ofstream file;
    file.open("BankSystem.txt",ios:: app);
    if (file.is_open())
    {
    file << "Basic" << endl;
    file << to_string(Balance) <<endl;
    file << "________________________________________________________"<<endl;
    }

    file.close();
  }
//==============================================================
BankAccount::~BankAccount()
{
}
