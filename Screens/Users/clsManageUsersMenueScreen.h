


#pragma once

#include <iostream>
#include <iomanip>
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsUsersListScreen.h";
#include "clsAddNewUserScreen.h";
#include "clsDeleteUsereScreen.h";
#include "clsUpdateuserScreen.h";
#include "clsFindUserScreen.h";

using namespace std;

class clsManageUsersMenueScreen : protected clsScreen
{

private:

    enum enManageUserMenueOption
    {
        ListUsers = 1, AddNewUser = 2,
        DleleteUser = 3, UpdateUser = 4,
        FindUser = 5, MainMenue = 6
    };


    static short _ReadManageUsersMenueScreenOption()
    {
        cout << "Choice what do you want to do From [1] To [6]    ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter number between 1 and 6");
        return Choice;
    }

    static void GoBackToManagUsersMenue()
    {
        cout << "\n\n\nPress any key to go back to main menue....";
        system("pause>0");

        ShowManageUserMenueScreen();
    }

    static void ShowListUsersScreen()
    {
        //cout << "Show List Users Screen is going to be here....\n ";

        clsUsersListScreen::ShowUsersList();

    }

    static void ShowAddNewUsersScreen()
    {
        clsAddNewUser::ShowAddNewUserScreen();
    }

    static void ShowDeleteUsersScreen()
    {
        clsDeleteUserScreen::ShoeDeleteUserScreen();
    }

    static void ShowUpdateUsersScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void ShowFindUsersScreen()
    {
        //cout << "Show Find Users Screen is going to be here....\n ";
        clsFindUserScreen::ShowFindUserScreen();
    }

   

    static void PerformManagUsersMenueOption(enManageUserMenueOption ManageUserMenueOption)
    {
        switch (ManageUserMenueOption)
        {
        case clsManageUsersMenueScreen::ListUsers:
            system("cls");
            ShowListUsersScreen();
            GoBackToManagUsersMenue();
            break;
        case clsManageUsersMenueScreen::AddNewUser:
            system("cls");
            ShowAddNewUsersScreen();
            GoBackToManagUsersMenue();
            break;
        case clsManageUsersMenueScreen::DleleteUser:
            system("cls");
            ShowDeleteUsersScreen();
            GoBackToManagUsersMenue();
            break;
        case clsManageUsersMenueScreen::UpdateUser:
            system("cls");
            ShowUpdateUsersScreen();
            GoBackToManagUsersMenue();
            break;
        case clsManageUsersMenueScreen::FindUser:
            system("cls");
            ShowFindUsersScreen();
            GoBackToManagUsersMenue();
            break;
        case clsManageUsersMenueScreen::MainMenue:
            break;
        default:
            break;
        }
    }

public:
    static void ShowManageUserMenueScreen()
    {

        if (!CheckAccess(clsUsers::pManageUsers))
        {
            return;
        }

        system("cls");
        clsScreen::_DrawScreenHeader("        Manage Users Screen  ");
        cout << setw(32) << "" << "====================================================\n";
        cout << setw(32) << "" << "              Manage Users Menue\n";
        cout << setw(32) << "" << "====================================================\n";
        cout << setw(32) << "" << "               [1] List Users.\n";
        cout << setw(32) << "" << "               [2] Add New User.\n";
        cout << setw(32) << "" << "               [3] Delete User.\n";
        cout << setw(32) << "" << "               [4] Update.\n";
        cout << setw(32) << "" << "               [5] Find User.\n";
        cout << setw(32) << "" << "               [6] Main Menue.\n";
        cout << setw(32) << "" << "====================================================\n";

        PerformManagUsersMenueOption(enManageUserMenueOption(_ReadManageUsersMenueScreenOption()));
    }



};  

