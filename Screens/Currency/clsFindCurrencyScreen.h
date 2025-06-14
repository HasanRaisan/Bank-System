

#pragma once

#include "clsInputValidate.h";
#include "clsCurrency.h";



// There is another way to solve Find Current under


class clsFindCurrencyScreen : protected clsScreen
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

	static void FindCurrencyScreen()
	{
		
		clsScreen::_DrawScreenHeader("   Find Currency Screen");


		string ReadFind = clsInputValidate::ReadString("Find By: [1] Code  or  [2] Country?  1/2    ");

		if (ReadFind == "1")
		{
			
			clsCurrency Currency = clsCurrency::FindByCode(_ReadCode());

			_Print(Currency);
		}
		else
		{

			clsCurrency Currency = clsCurrency::FindByCountry(_ReadCountry());
			_Print(Currency);
		}

	}

};


// Another way to solv Find Currency


//
//
//#pragma once
//#include <iostream>
//#include "clsScreen.h"
//#include "clsCurrency.h"
//#include "clsInputValidate.h"
//
//class clsFindCurrencyScreen :protected clsScreen
//{
//
//private:
//    static void _PrintCurrency(clsCurrency Currency)
//    {
//        cout << "\nCurrency Card:\n";
//        cout << "_____________________________\n";
//        cout << "\nCountry    : " << Currency.Country();
//        cout << "\nCode       : " << Currency.CurrencyCode();
//        cout << "\nName       : " << Currency.CurrencyName();
//        cout << "\nRate(1$) = : " << Currency.Rate();
//
//        cout << "\n_____________________________\n";
//
//    }
//
//    static void _ShowResults(clsCurrency Currency)
//    {
//        if (!Currency.IsEmpty())
//        {
//            cout << "\nCurrency Found :-)\n";
//            _PrintCurrency(Currency);
//        }
//        else
//        {
//            cout << "\nCurrency Was not Found :-(\n";
//        }
//    }
//
//public:
//
//    static void ShowFindCurrencyScreen()
//    {
//
//        _DrawScreenHeader("\t  Find Currency Screen");
//
//        cout << "\nFind By: [1] Code or [2] Country ? ";
//        short Answer = 1;
//
//        cin >> Answer;
//
//        if (Answer == 1)
//        {
//            string CurrencyCode;
//            cout << "\nPlease Enter CurrencyCode: ";
//            CurrencyCode = clsInputValidate::ReadString();
//            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
//            _ShowResults(Currency);
//        }
//        else
//        {
//            string Country;
//            cout << "\nPlease Enter Country Name: ";
//            Country = clsInputValidate::ReadString();
//            clsCurrency Currency = clsCurrency::FindByCountry(Country);
//            _ShowResults(Currency);
//        }
//
//
//
//
//
//
//    }
//
//};
//
