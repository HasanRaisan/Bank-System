

#pragma once

#include "clsScreen.h";
#include "clsCurrency.h";
#include "clsInputValidate.h";


class clsUpdateCurrenctRateScreen : protected clsScreen
{

private:

	static void _Print(clsCurrency Currency)
	{
		cout << "\n    Currency Info:\n\n";
		cout << "--------------------------------------\n";
		cout << "Country      :" << Currency.Country() << endl;
		cout << "Currency Code:" << Currency.CurrencyCode() << endl;
		cout << "Country Nae  :" << Currency.CurrencyName() << endl;
		cout << "Country Rate :" << Currency.Rate() << endl;
		cout << "--------------------------------------\n";
	}

	static string _ReadCode()
	{
		string Code = clsInputValidate::ReadString("\nEnter The Code:   ");
		while (!clsCurrency::IsCurrencyExistByCode(Code))
		{
			Code = clsInputValidate::ReadString("\n The Code is not exist! Enter again:   ");
		}
		return Code;
	}

	static string _ReadCountry()
	{
		string Country = clsInputValidate::ReadString("\nEnter The Country:   ");
		while (!clsCurrency::IsCurrencyExistByCountry(Country))
		{
			Country = clsInputValidate::ReadString("\n The Country is not exist! Enter again:   ");
		}
		return Country;
	}


public:


	static void UpdateCurrencyRateScreen()
	{

		clsScreen::_DrawScreenHeader("   Update Currency Rate Screen");


		string ReadFind = clsInputValidate::ReadString("Find By: [1] Code  or  [2] Country?  1/2    ");

		if (ReadFind == "1")
		{
			clsCurrency Currency = clsCurrency::FindByCode(_ReadCode());

			_Print(Currency);

			cout << "\nAre you sure you want to update the rate of this Currency y/n? ";
			char Answer = 'n';
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				cout << "\nEnter the new rate:   ";
				float NewRate = clsInputValidate::ReadFloatNumber();

				Currency.UpdateRate(NewRate);

				cout << "\nThe update is successful :-)\n";

				_Print(Currency);
			}

		}
		else
		{
			clsCurrency Currency = clsCurrency::FindByCountry(_ReadCountry());
			_Print(Currency);


			cout << "\nAre you sure you want to update the rate of this Currency y/n? ";
			char Answer = 'n';
			cin >> Answer;

			cout << "\nEnter the new rate:   ";

			if (Answer == 'y' || Answer == 'Y')
			{
				cout << "\nEnter the new rate:   ";
				float NewRate = clsInputValidate::ReadFloatNumber();

				Currency.UpdateRate(NewRate);

				cout << "\nThe update is successful :-)\n";

				_Print(Currency);
			}
			
		}



	}

};

