#include "Client.h"
Client :: Client(){}
Client::Client(string input_name, string input_address , string input_phone)
{
    name = input_name;
    address = input_address;
    number = input_phone;
}
//==========================================================================================
void Client :: fill_file()
{
    ofstream file;
    string Id = "FCAI-"+to_string(count);
    file.open("BankSystem.txt",ios:: app);
    if (file.is_open())
    {
    file<< name <<endl;
    file << address <<endl;
    file << number <<endl;
    file << Id <<endl;
    }
    count++;

    file.close();
}
//==========================================================================================
int Client :: getType()
{
    return type;
}
//==========================================================================================
int Client :: getBindex()
{
    return Bindex;
}
//==========================================================================================
void Client :: print()
{
    ifstream file("BankSystem.txt",ios::app);
    if (file.is_open())
        cout << file.rdbuf();
    file.close();
}
//==========================================================================================
bool Client :: print_specific(string & Id)
{
    ifstream file;
    vector<string>text;
    char line[100];
    string I,B,T;
    bool check =false;
    file.open ("BankSystem.txt",ios::app);
     while (!file.eof())
    {
        file.getline(line, 100, '\n');
        text.push_back(string(line));
    }
    for(int i=0;i<text.size();i++){
            if(Id==string(text[i])){
                I=string(text[i]);
                T=string(text[i+1]);
                B=string(text[i+2]);
                cout<<"Account ID: "<<I<<endl;
                cout<<"Account Type: "<<T<<endl;
                if(T=="Basic")
                    type = 1;
                else if (T=="Saving")
                    type = 2;
                cout<<"Balance: "<<B<<endl;
                Bindex=i+2;
                check=true;
                break;
            }
    }
    if(!check)
        {
            return false;
        }
    else return true;
    file.close();
}
//==========================================================================================
Client::~Client()
{
}
