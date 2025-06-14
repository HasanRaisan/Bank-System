
#include <iostream>
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsBankClient.h";


#pragma once

class clsUpdateClientScreen : public clsScreen
{

private:

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

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

    static void UpdateClientScreen()
    {

        if (!CheckAccess(clsUsers::pUpdateClients))
        {
            return;
        }


        clsScreen::_DrawScreenHeader("Update Client Screen");
        cout << "Enter account number to update.\n";
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "This account numbet is not exsit! enter again.";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _Print(Client);
        char update = 'n';
        cout << "\n\n Are you sure you want update this? y/n    ";
        cin >> update;

        if (update == 'y' || update == 'Y')
        {
            cout << "\n\nUpdate Client Information\n";
            cout << "---------------------------------\n\n";
            _ReadClientInfo(Client);
            clsBankClient::enSaveResults SaveResult = Client.Save();
            switch (SaveResult)
            {
            case clsBankClient::svFaildEmptyObject:
                cout << "Save is faild becouse it's empty.\n";
                break;
            case clsBankClient::svSucceeded:
                cout << "Account update is successfu -:) \n";
                _Print(Client);
                break;
            default:
                break;
            }
        }

    }
	
};

