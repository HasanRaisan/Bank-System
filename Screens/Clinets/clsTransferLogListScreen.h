

#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsBankClient.h";


class clsTransferLogListScreen :protected clsScreen
{

private:

    static void PrintTransferLogRecordLine(clsBankClient::stTransferProcessData TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateAndTime;
        cout << "| " << setw(8) << left << TransferLogRecord.SourceClientAccount;
        cout << "| " << setw(8) << left << TransferLogRecord.DestinationClientAccount;
        cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.SourceClientBalance;
        cout << "| " << setw(10) << left << TransferLogRecord.DestinationClientBalacne;
        cout << "| " << setw(8) << left << TransferLogRecord.UserName;


    }

public:

    static void ShowTransferLogScreen()
    {


        vector <clsBankClient::stTransferProcessData> vTransferLogRecord = clsBankClient::_LoadTransferDateFromFile();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransferProcessData Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};


