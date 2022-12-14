#include "BankApplication.h"

BankApplication::BankApplication()
{
}
void BankApplication :: menu()
{
    while (true)

    {
        cout<<"Welcome to FCAI Banking Application :) \n"
        <<"1. Create a New Account \n"
        <<"2. List Clients and Accounts \n"
        <<"3. Withdraw Money \n"
        <<"4. Deposit Money \n"
        <<"5.Exit\n";
        int choice;
        string input_name,input_address,input_phone,Id;
        double input_Balance,value;
        cout<<"Please Enter Choice =========>";
        cin>>choice;
         if (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "You can only enter numbers.\n";
    }
        if(choice==1)
        {
            cout << "Please Enter Client Name =========> ";
            cin.ignore();
            getline(cin,input_name);
            cout << "Please Enter Client Address =======> ";
            getline(cin,input_address);
            cout << "Please Enter Client Phone =======> ";
            getline(cin,input_phone);
            cout<<"What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========> ";
            int answer;
            cin >> answer;
            if(answer == 1)
            {
                cout << "Please Enter the Starting Balance =========> ";
                cin>>input_Balance;
                Client newclient(input_name,input_address,input_phone);
                newclient.fill_file();
                BankAccount newBank(input_Balance);
                newBank.fill_file();
                cout<<"An account was created with ID FCAI-" << newclient.getcount()-1 << " and Starting Balance "<<newBank.getBalance()<<" L.E.\n";
            }
            else if (answer == 2)
            {
                cout << "Please Enter the Starting Balance which is more than or equal 1000=========> ";
                cin>>input_Balance;
                if (input_Balance>=1000)
                    {
                        Client newclient(input_name,input_address,input_phone);
                        newclient.fill_file();
                        SavingBankAccount newBank(input_Balance);
                        newBank.fill_file();
                        cout<<"An account was created with ID FCAI-" << newclient.getcount() << " and Starting Balance "<<newBank.getBalance()<<" L.E.\n";
                    }
                else
                    {
                        cout<<"Invalid Balance :(\n";
                    }

            }
            else
                {
                    cout<<"Invalid Choice :(\n";
                }

        }
        else if(choice == 2)
        {
            Client newclient;
            newclient.print();
        }
        else if (choice == 3)
        {
            Client Newclient;
            cout<<"Please Enter Account ID (e.g., FCAI-1) =========> ";
            cin>>Id;
            Newclient.print_specific(Id);
            if(Newclient.print_specific(Id))
            {
                cout<<"Please Enter The Amount to Withdraw =========> ";
                cin >> value;
                if(Newclient.getType()==1)
                {
                    BankAccount newaccount;
                    newaccount.withdraw(value,Newclient.getBindex());
                }
                else if (Newclient.getType()==2)
                {
                    SavingBankAccount newaccount;
                    newaccount.withdraw(value,Newclient.getBindex());
                }
            }
            else cout<<" Wrong Id :("<<endl;


        }
        else if (choice == 4)
        {
            Client Newclient;
            cout<<"Please Enter Account ID (e.g., FCAI-1) =========> ";
            cin>>Id;
            Newclient.print_specific(Id);
            if(Newclient.print_specific(Id))
            {
                cout<<"Please Enter The Amount to Deposit =========> ";
                cin >> value;
                if(Newclient.getType()==1)
                {
                    BankAccount newaccount;
                    newaccount.deposit(value,Newclient.getBindex());
                }
                else if (Newclient.getType()==2)
                {
                    SavingBankAccount newaccount;
                    newaccount.deposit(value,Newclient.getBindex());
                }
            }
            else cout<<" Wrong Id :("<<endl;



        }
        else if (choice == 5)
        {
            cout << "Thank you for using MAN's bank system :D" << endl;
            exit(1);
        }
        else
            cout<<"Valid Input :(\n ";
    }

}
BankApplication::~BankApplication()
{
}

