#pragma once

#include <iostream>
#include "clsInputValidate.h";
#include "clsBankClient.h";
#include "clsScreen.h";

class clsFindClientScreen : public clsScreen
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

    static void FindClientScreen()
    {
        if (!CheckAccess(clsUsers::pFindClient))
        {
            return;
        }


        clsScreen::_DrawScreenHeader("Find Client Screen");

        cout << "Enter account number      ";
        string AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account number is not exist! enter again     ";
             AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if (!Client.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Not Found :-(\n";
        }

        _Print(Client);
    }
};

