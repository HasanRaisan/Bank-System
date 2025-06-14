



#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h";
#include "clsWithdrawScreen.h";
#include "clsTotalBalacneScreen.h";
#include "clsTransferScreen.h";
#include "clsTransferLogListScreen.h";

using namespace std;


class clsTransactionsScreen : protected clsScreen
{


private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4
         , eTransferLog = 5,eShowMainMenue = 6
    };

    static short ReadTransactionsMenueOption()
    {
      std::cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToTransactionsMenue()
    {
        std::cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }
    
    static void _ShowWithdrawScreen()
    {
      //   cout << "\n Withdraw Screen will be here.\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalacneScreen::ShowTotalBalances();
    }


    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferScreenLog()
    {
        clsTransferLogListScreen::ShowTransferLogScreen();
    }

 

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eTransfer:

            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;


        case enTransactionsMenueOptions::eTransferLog:

            system("cls");
            _ShowTransferScreenLog();
            _GoBackToTransactionsMenue();
            break;


        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }

        }


    }



public:


    static void ShowTransactionsMenue()
    {

        if (!CheckAccess(clsUsers::pTranactions))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        std::cout << setw(37) << left << "" << "===========================================\n";
        std::cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        std::cout << setw(37) << left << "" << "===========================================\n";
        std::cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        std::cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        std::cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        std::cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        std::cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        std::cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        std::cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }

};

