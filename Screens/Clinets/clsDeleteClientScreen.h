

#pragma once

#include <iostream>
#include "clsInputValidate.h";
#include "clsBankClient.h";
#include "clsScreen.h";

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{

private:
	
    static void _Print(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";
    }

public:


    static void ShowDeleteClient()
    {

        if (!CheckAccess(clsUsers::pDeleteClient))
        {
            return;
        }
        clsScreen::_DrawScreenHeader("       Delete Client Screen");
        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _Print(Client1);

        cout << "\nAre you sure you want to delete this client y/n? ";

        char answer = 'n';
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            if (Client1.Delete())
            {
                cout << "Delete is sccessful.\n";
            }
            else
            {
                cout << "Delete is failed. Go to the hell \n";
            }
            
        }
    }

};

