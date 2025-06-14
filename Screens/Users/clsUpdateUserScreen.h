#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUsers.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen :protected clsScreen

{
private:


    static void _ReadUserInfo(clsUsers& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadAccess();
    }

	static short _ReadAccess()
	{
		short Access = 0;
		char Answer = 'n';

		Answer = clsInputValidate::ReadChar("\nDo You Want Give This User full Access?  y/n     ");
		if (Answer == 'y' || Answer == 'Y')
			return Access = -1;

		Answer = clsInputValidate::ReadChar("Do You Want Give This User Access on Client List?  y/n     ");
		if (Answer == 'y' || Answer == 'Y')
			Access = 1;

		Answer = clsInputValidate::ReadChar("Do You Want Give This User Access on Add New Client? y/n     ");
		if (Answer == 'y' || Answer == 'Y')
			Access += 2;

		Answer = clsInputValidate::ReadChar("Do You Want Give This User Access on Delete Client? y/n     ");
		if (Answer == 'y' || Answer == 'Y')
			Access += 4;

		Answer = clsInputValidate::ReadChar("Do You Want Give This User Access on Update Client? y/n     ");
		if (Answer == 'y' || Answer == 'Y')
			Access += 8;

		Answer = clsInputValidate::ReadChar("Do You Want Give This User Access on Find Client? y/n     ");
		if (Answer == 'y' || Answer == 'Y')
			Access += 16;

		Answer = clsInputValidate::ReadChar("Do You Want Give This User Access on Transactions Client? y/n     ");
		if (Answer == 'y' || Answer == 'Y')
			Access += 32;

		Answer = clsInputValidate::ReadChar("Do You Want Give This User Access on Manage Users? y/n     ");
		if (Answer == 'y' || Answer == 'Y')
			Access += 64;

        Answer = clsInputValidate::ReadChar("Do You Want Give This User Access on  Login RegisternList? y/n     ");
        if (Answer == 'y' || Answer == 'Y')
            Access += 128;


		return Access;
	}

	static void _PrintUser(clsUsers User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}

public:

    static void ShowUpdateUserScreen()
    {

        _DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";

        cout << "\nPlease Enter User UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUsers::IsUserExsit(UserName))
        {
            cout << "\nAccount number is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUsers User1 = clsUsers::Find(UserName);

        _PrintUser(User1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _ReadUserInfo(User1);

            clsUsers::SaveResult SaveResult;

            SaveResult = User1.Save();

            switch (SaveResult)
            {
            case  clsUsers::SaveResult::eSaveSuccess:
            {
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(User1);
                break;
            }
            case clsUsers::SaveResult::eSaveFailBecuoceEmpty:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }

            }

        }

    }

};