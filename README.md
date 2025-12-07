# Integrated Banking Management System in C++

An advanced **Object-Oriented (OOP)** command-line banking system built in **C++**, designed to simulate real banking operations with local persistent data stored in text files.

This system focuses heavily on **OOP principles (Encapsulation, Abstraction, Inheritance, Polymorphism)** and a modular project structure to ensure clean code, scalability, and maintainability.

---

# 🧰 Main Functions

## 👥 Customer Management

- View / Add / Delete / Update customers
- Search customers by account number

## 💰 Banking Operations

- Deposit
- Withdraw
- Transfer between accounts
- Display total balances
- Transfer history log

## 👤 User Management

- Add / Delete / Update users
- Permission control:
  - View only
  - Perform operations
  - Full access

## 💱 Currency Exchange

- View currencies
- Search currencies
- Update exchange rates
- Currency calculator

## 🗂️ System & Security

- Login management
- Usage logs (audit trail)

---

# 🗄️ Data Storage Method

All data is stored locally in **.txt files**, with records saved as lines separated by a unique delimiter (such as `#//#`).

This makes the system simple, portable, and easy to maintain for educational purposes.

---

# 🛠️ Requirements

- C++ compiler (MSVC, GCC, Clang)
- Command Line (Windows CMD / Linux Terminal)

---

# 💻 Technologies Used

- **C++ Programming Language**
- **Command-Line Interface (CLI)**
- **Object-Oriented Programming (OOP) Concepts**
  - Classes & Objects
  - Inheritance
  - Polymorphism
  - Encapsulation
  - Abstraction
- **File-Based Local Storage**

> 🧠 **The project strongly focuses on OOP design**, creating a modular, layered system with reusable, clean classes.

---

# 🗂️ Project Structure

Below is the full project structure as shown in the uploaded image:

```
Bank
│
├── Header Files
│   ├── Core
│   │   ├── clsBankClient.h
│   │   ├── clsCurrency.h
│   │   ├── clsPerson.h
│   │   └── clsUsers.h
│   │
│   ├── Library
│   │   ├── clsDate.h
│   │   ├── clsInputValidate.h
│   │   ├── clsString.h
│   │   └── clsUtility.h
│   │
│   ├── Screens
│   │   ├── Clients
│   │   │   ├── clsClientAddNewScreen.h
│   │   │   ├── clsClientListScreen.h
│   │   │   ├── clsDeleteClientScreen.h
│   │   │   ├── clsDepositScreen.h
│   │   │   ├── clsFindClientScreen.h
│   │   │   ├── clsTotalBalanceScreen.h
│   │   │   ├── clsTransactionMenueScreen.h
│   │   │   ├── clsTransferLogListScreen.h
│   │   │   ├── clsTransferScreen.h
│   │   │   ├── clsUpdateClientScreen.h
│   │   │   └── clsWithdrawScreen.h
│   │   │
│   │   ├── Currency
│   │   │   ├── clsCurrencyCalculatorScreen.h
│   │   │   ├── clsCurrencyExchangeMainScreen.h
│   │   │   ├── clsCurrencyListScreen.h
│   │   │   └── clsFindCurrencyScreen.h
│   │   │
│   │   ├── Users
│   │   │   ├── clsAddNewUserScreen.h
│   │   │   ├── clsDeleteUserScreen.h
│   │   │   ├── clsFindUserScreen.h
│   │   │   ├── clsLoginRegisterScreen.h
│   │   │   ├── clsLoginScreen.h
│   │   │   ├── clsManageUsersMenueScreen.h
│   │   │   ├── clsUpdateUserScreen.h
│   │   │   └── clsUsersListScreen.h
│   │   │
│   │   ├── clsMainScreen.h
│   │   └── clsScreen.h
│   │
│   └── Global.h
│
├── Source Files
│   └── Bank.cpp
```

---

# 👤 Default Test Account

- **Username:** u1
- **Password:** 1234

---

# 🚀 Preview

- **[Login Screen](https://drive.google.com/file/d/1ijCd3IsaEEF20W7Uz8BvcuEYSEyYfH21/view?usp=drive_link)**
- **[Main Screen](https://drive.google.com/file/d/17oRxM424EHMOQx6qdQU_TJafR68oShq3/view?usp=drive_link)**
- **[Transactions Screen](https://drive.google.com/file/d/1fkov7Dl04g9Y1t89aqJRgDbmm4CGZljX/view?usp=drive_link)**
- **[Manage Users Screen](https://drive.google.com/file/d/1rSjj5r87eUtIifPbkxJW-8bleftG83er/view?usp=drive_link)**
- **[Currency Exchange Main Screen](https://drive.google.com/file/d/1xVCHjmK1GOi4iBiKM2Pf5UvbezP3Yb0M/view?usp=drive_link)**

---

# 👨‍💻 Developer

**Hassan Raisan**

🔗 [LinkedIn](https://www.linkedin.com/in/hasan-raisan-949b84241/)  
📧 hasan.raisann@gmail.com  
💼 Full-Stack Developer
