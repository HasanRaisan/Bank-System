#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

string _ClientsFileName = "Data/Clients.txt";

class clsBankClient : public clsPerson
{


private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDelete = false;


    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], clsUtil::DecryptText(vClientData[5], 7), stod(vClientData[6]));

    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += clsUtil::EncryptText(Client.PinCode,7) + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open(_ClientsFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);
                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open(_ClientsFileName, ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C.GetMarkToDelete() == false)
                {
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();

        }

    }
    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open(_ClientsFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }


    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }


    string _PrepareTransferLogRecord(double Amount, clsBankClient DestinationClient, string Sparate = "#//#")
    {
        string Line = clsDate::GetSystemDateTimeString() + Sparate;
        Line += AccountNumber() + Sparate;
        Line += DestinationClient.AccountNumber() + Sparate;
        Line += to_string(Amount) + Sparate;
        Line += to_string(AccountBalance) + Sparate;
        Line += to_string(DestinationClient.AccountBalance) + Sparate;
        Line += CurrentUser.UserName;
        return Line;
    }
    void _TransferRegister(double Amount, clsBankClient DestinationClient)
    {
        string Line = _PrepareTransferLogRecord(Amount, DestinationClient);

        fstream File;
        File.open("Data/TransferRegister.txt", ios::out | ios::app);

        if (File.is_open())
        {
            File << Line << endl;
        }

        File.close();
    }


public:


    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    bool GetMarkToDelete()
    {
        return _MarkForDelete;
    }
    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    // Move to User enter face
    //void Print()
    //{
    //    cout << "\nClient Card:";
    //    cout << "\n___________________";
    //    cout << "\nFirstName   : " << FirstName;
    //    cout << "\nLastName    : " << LastName;
    //    cout << "\nFull Name   : " << FullName();
    //    cout << "\nEmail       : " << Email;
    //    cout << "\nPhone       : " << Phone;
    //    cout << "\nAcc. Number : " << _AccountNumber;
    //    cout << "\nPassword    : " << _PinCode;
    //    cout << "\nBalance     : " << _AccountBalance;
    //    cout << "\n___________________\n";

    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open(_ClientsFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open(_ClientsFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };


    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {

                return enSaveResults::svFaildEmptyObject;

            }

        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:


            if (IsClientExist(this->AccountNumber()))
            {
                cout << "This client is already exist!\n";
                return enSaveResults::svFaildAccountNumberExists;
            }

            else
            {
                this->_AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }



        }

    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }


    bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkForDelete = true;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;

    }

    static vector < clsBankClient > GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }



    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;

    }



    void Deposit(long int Amount)
    {
        _AccountBalance += Amount;
        Save();
    }


    bool Withdraw(long int Amount)
    {
        if (_AccountBalance <= Amount)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
        }
    }


    bool Transfer(double Amount, clsBankClient& DestinationClient)
    {
        if (Amount > AccountBalance)
            return false;

        Withdraw(Amount);
        DestinationClient.Deposit(Amount);

        _TransferRegister(Amount, DestinationClient);
        return true;

    }



    struct stTransferProcessData
    {
        string DateAndTime = "";
        string SourceClientAccount = "";
        string DestinationClientAccount = "";
        double Amount = 0;
        double SourceClientBalance = 0;
        double DestinationClientBalacne = 0;
        string UserName = "";
    };
    static stTransferProcessData _ConvertLineTransferDateToRecord(string Line)
    {

        vector <string> vTranfer = clsString::Split(Line, "#//#");

        stTransferProcessData TransferDate;
        TransferDate.DateAndTime = vTranfer[0];
        TransferDate.SourceClientAccount = vTranfer[1];
        TransferDate.DestinationClientAccount = vTranfer[2];
        TransferDate.Amount = stod(vTranfer[3]);
        TransferDate.SourceClientBalance = stod(vTranfer[4]);
        TransferDate.DestinationClientBalacne = stod(vTranfer[5]);
        TransferDate.UserName = vTranfer[6];                    
        
        return TransferDate;
    };
 
    static vector < stTransferProcessData> _LoadTransferDateFromFile()
    {

        vector < stTransferProcessData> vTransferDate;

        fstream File;
            
        File.open("Data/TransferRegister.txt", ios::in);

        if (File.is_open())
        {
            string Line = "";
            while (getline(File,Line))
            {
                vTransferDate.push_back(_ConvertLineTransferDateToRecord(Line));
            }
        }

        File.close();

        return vTransferDate;
    }


};

