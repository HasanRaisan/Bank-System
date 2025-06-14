

#pragma once


#include <iostream>
#include <string>.
#include <vector>
#include <fstream>
#include "clsPerson.h";
#include "clsString.h";
#include "clsInputValidate.h";

#include "clsUtility.h";


using namespace std;

string _UsersFileName = "Data/Users.txt";

class clsUsers : public clsPerson
{
	
private:

	string _UserName = "";
	string _Password = "";
	bool _MarkedForDeleted = false;
	int _Permissions = 0;
	
	enum enMode {eEmpty =0 , eUpadate = 1 , eAddNew = 2};
	enMode _Mode;

	static clsUsers _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUserlDaa;
		vUserlDaa = clsString::Split(Line, Seperator);

		return clsUsers(enMode::eUpadate, vUserlDaa[0], vUserlDaa[1], vUserlDaa[2],
			vUserlDaa[3], vUserlDaa[4], clsUtil::DecryptText(vUserlDaa[5],7), stoi(vUserlDaa[6]));

	}
	static  vector <clsUsers> _LoadUsersDataFromFile()
	{

		vector <clsUsers> vUsers;

		fstream MyFile;
		MyFile.open(_UsersFileName, ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsUsers User = _ConvertLinetoUserObject(Line);


				vUsers.push_back(User);
			}

			MyFile.close();

		}

		return vUsers;

	}


	static string _ConverUserObjectToLine(clsUsers User, string Seperator = "#//#")
	{

		User.Password = clsUtil::EncryptText(User.Password, 7);
		string UserRecord = "";
		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User.UserName + Seperator;
		UserRecord += User.Password + Seperator;
		UserRecord += to_string(User.GetPermissions());

		return UserRecord;

	}

	static void _SaveUsersDataToFile(vector <clsUsers> vUsers)
	{

		fstream MyFile;
		MyFile.open(_UsersFileName, ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsUsers U : vUsers)
			{
				if (U._MarkedForDeleted == false)
				{
					//we only write records that are not marked for delete.  

					DataLine = _ConverUserObjectToLine(U);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}
	void _AddDateLineToFile(string strDateLine)
	{
		fstream File;
		File.open(_UsersFileName, ios::out | ios::app);

		if (File.is_open())
		{
			File << strDateLine << endl;
			File.close();
		}
	}


	static clsUsers _GetEmptyUserObject()
	{
		return clsUsers(enMode::eEmpty, "", "", "", "", "", "",0);
	}

	void _Update()
	{
		vector <clsUsers> vUsers = _LoadUsersDataFromFile();
		for (clsUsers& U : vUsers)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}
	void _AddNew()
	{
		_AddDateLineToFile(_ConverUserObjectToLine(*this));
	}

	
public:


	

	clsUsers(enMode Mode,string FirstName, string LastName, string Email,string Phone,string
		AccountNumber, string PinCode , int Access)
		: clsPerson(FirstName,LastName,Email,Phone)
	{
		this->_Mode = Mode;
		this->UserName = AccountNumber;
		this->Password = PinCode;
		this->_Permissions = Access;
	}



    string GetAccountNumber()
	{
		return this->_UserName;
	}
	void SetAccountNumber(string AccountNumber)
	{
		this->_UserName = AccountNumber;
	}
	string GetPassword()
	{
		return this->_Password;
	}
	void SetMode(enMode Mode)
	{
		this->_Mode = Mode;
	}
	enMode GetMode()
	{
		return this->_Mode;
	}
	void SetPassword(string Password)
	{
		this->_Password = Password;
	}



	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}


	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;
	__declspec(property(get = GetAccountNumber, put = SetAccountNumber)) string UserName;
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;



	bool IsEmpty()
	{
		return (_Mode == enMode::eEmpty);
	}
	

	static clsUsers Find(string UserName)
	{
		vector < clsUsers> vUsers = _LoadUsersDataFromFile();

		for (clsUsers& U : vUsers)
		{
			if (U.UserName == UserName)
				return U;
		}

		return _GetEmptyUserObject();
	}
	static clsUsers Find(string AccountNumber , string PINCod)
	{
		clsUsers User = Find(AccountNumber);
		if (User.Password == PINCod)
			return User;
		else
			return _GetEmptyUserObject();
	
	}

	static clsUsers AddNewoUser(string AccountNumber)
	{
		return clsUsers(enMode::eAddNew, "", "", "", "", AccountNumber, "", 0);
	}
	
	enum SaveResult { eSaveFailBecuoceEmpty=0 , eSaveSuccess =1, eFaildUserExsits};

	SaveResult Save()
	{
		switch (_Mode)
		{
		case clsUsers::eEmpty:
			if (IsEmpty())
			{
			return SaveResult::eSaveFailBecuoceEmpty;

			}
			break;

		case clsUsers::eUpadate:
			_Update();
			return SaveResult::eSaveSuccess;
			break;

		case clsUsers::eAddNew:

			if (clsUsers::IsUserExsit(UserName))
			{
				return SaveResult::eFaildUserExsits;
			}
			else
			{
				_AddNew();
				SetMode(enMode::eUpadate);
			return SaveResult::eSaveSuccess;

			}
			break;
		default:
			break;
		}
	}

	bool Delete()
	{
		vector <clsUsers> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUsers& U : _vUsers)
		{
			if (U.UserName == _UserName)
			{
				U._MarkedForDeleted = true;
				break;
			}

		}
		_SaveUsersDataToFile(_vUsers);

		*this = _GetEmptyUserObject();
		return true;

	}



	static bool IsUserExsit(string AccountNumber)
	{
		clsUsers User = Find(AccountNumber);
		return (!User.IsEmpty());
	}

	static vector < clsUsers> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}


	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
		, pLoingRegister = 128

	};
	bool CheckAccessPermission(enPermissions Permissions)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;
		if ((Permissions & this->Permissions) == Permissions)
			return true;
		return false;
	}


	string _PrepareLogInRecord(string Seperator = "#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += UserName + Seperator;
		// Encrypt
		LoginRecord += clsUtil::EncryptText(Password,7) + Seperator;
		LoginRecord += to_string(Permissions);
		return LoginRecord;
	}
	void RegisterLogIn()
	{

		string stDataLine = _PrepareLogInRecord();

		fstream MyFile;

		MyFile.open("Data/LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;

	};

	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;


		vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
		LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		// Descrypt
		LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2],7);
		LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

		return LoginRegisterRecord;

	}
	static  vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector <stLoginRegisterRecord> vLoginRegisterRecord;

		fstream MyFile;
		MyFile.open("Data/LoginRegister.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stLoginRegisterRecord LoginRegisterRecord;

			while (getline(MyFile, Line))
			{

				LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

				vLoginRegisterRecord.push_back(LoginRegisterRecord);

			}

			MyFile.close();

		}

		return vLoginRegisterRecord;

	}

};

