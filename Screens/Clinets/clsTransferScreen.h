
#pragma once

#include <iostream>
#include <string>
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsBankClient.h";

using namespace std;

class clsTransferScreen : protected clsScreen
{

private:

	static void _PrintClientInfo(clsBankClient Client)
	{
		cout << "\n\n Client Info: \n";
		cout << "_________________________________\n";
		cout << "Full Name      : " << Client.FullName() << endl;
		cout << "Account  Number: " << Client.AccountNumber() << endl;
		cout << "Account Balance: " << Client.AccountBalance << endl;
		cout << "_________________________________\n\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = clsInputValidate::ReadString("\nEnter the account number you want tranfer From.\t");

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "The Account Number is not exist! Enter again    ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		cout << "\nEnter Transfer Amount  ";
		return clsInputValidate::ReadDblNumberBetween(1, SourceClient.AccountBalance, "Number is not beteen 1 and " + to_string(int(SourceClient.AccountBalance)) + ", Enter again:   ");
	}

public:

	static void ShowTransferScreen()
	{
		clsScreen::_DrawScreenHeader("\t\t\tTransfer Screen");
		

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientInfo(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientInfo(DestinationClient);

		double Amount = _ReadAmount(SourceClient);
		

		char cha = clsInputValidate::ReadChar("\nAre you sure you want to perform this operation ? y/n    ");

		if (cha == 'y' || cha == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient))
				cout << "\n\nThe Transfer is successful -:)\n\n The Balance become:\n";
		}

		_PrintClientInfo(SourceClient);
		_PrintClientInfo(DestinationClient);

		
	}

};