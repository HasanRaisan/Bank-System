

#pragma once

#include <iostream>
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsUsers.h";

using namespace std;

class clsAddNewUser : protected clsScreen
{

private:

	static void _ReadUserInfo(clsUsers& User)
	{
		cout <<  "\nFirst Name:  ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nLast Name:  ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEmail    :  ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nPhone    :  ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nPassword  :  ";
		User.Password = clsInputValidate::ReadString();

		User.SetPermissions(_ReadAccess());
	}
	
	static short _ReadAccess()
	{
		short Access = 0;
		char Answer = 'n';

		Answer = clsInputValidate::ReadChar("\nDo You Want Give This User full Access?  y/n     ");
		if (Answer == 'y' || Answer == 'Y')																       
			return Access = -1;																			       
																										       
		Answer = clsInputValidate::ReadChar("Do You Want Give This User Access on List Client?  y/n     ");
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

		Answer = clsInputValidate::ReadChar("Do You Want Give This User Access on List Login Register? y/n     ");
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
		cout << "\nPermissions : " << User.GetPermissions();
		cout << "\n___________________\n";

	}


public:

	static void ShowAddNewUserScreen()
	{
		clsScreen::_DrawScreenHeader("     Add New User Screen");

		cout << "Please enter account number    ";
		string AccountNumber = clsInputValidate::ReadString();
		while (clsUsers::IsUserExsit(AccountNumber))
		{
			cout << "This account is already used! enter a another account    ";
		    AccountNumber = clsInputValidate::ReadString();
		}
		clsUsers User = clsUsers::AddNewoUser(AccountNumber);

		_ReadUserInfo(User);

		clsUsers::SaveResult SaveResult;

		SaveResult = User.Save();

		switch (SaveResult)
		{
		case clsUsers::eSaveFailBecuoceEmpty:
			cout << "\n\nSave is Faild because the object is empty/\n";
			break;
		case clsUsers::eSaveSuccess:
			cout << "\n\nSave is success\n";
			break;
		case clsUsers::eFaildUserExsits:
			cout << "\n\nSave is Faild because the username already used\n";

			break;
		default:
			break;
		}


	}

};