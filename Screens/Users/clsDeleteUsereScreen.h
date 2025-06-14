

#pragma once

#include <iostream>
#include <string>
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsUsers.h";

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{

private:

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

	static void ShoeDeleteUserScreen()
	{
		cout << "Enter Username you want delete it     ";
		string UserName = clsInputValidate::ReadString();

		while (!clsUsers::IsUserExsit(UserName))
		{
			cout << "The Username [" << UserName << "] " << "Not Found! Enter Another UserName     ";
			UserName = clsInputValidate::ReadString();
		}

		clsUsers User = clsUsers::Find(UserName);
		_PrintUser(User);

		char cha = clsInputValidate::ReadChar("\n\nAre yoy sure you want delete this user?  y/n    ");
		
		if (cha == 'y' || cha == 'Y')
		{
			if (User.Delete())
			{
				cout << "\n\n The deletion process has been successful.\n\n";
				_PrintUser(User);
			}
			else
				cout << "\n\n The deletion process has been failed.\n\n";
		}
		else
		{
			cout << "\n\n The deletion process is canceled.\n\n";
		}
	}


};