#ifndef CLIENT_
#define CLIENT_
#include "BankAccount.h"
#include "Client.h"
#include <bits/stdc++.h>
using namespace std;

class Client
{
    public:
        Client();
        Client(string input_name, string input_address , string input_phone);
        void fill_file();
        void print();
        int getcount( ){ return count; }
        int getType();
        int getBindex();
        bool print_specific(string & Id);
        virtual ~Client();

    protected:
        string name;
        string address;
        string number;
        int type,Bindex;
        static int count;

    private:
};

#endif // CLIENT_
