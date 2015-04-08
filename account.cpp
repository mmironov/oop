#include "account.h"
#include <iostream>
#include <cstring>
using namespace std;

Account::Account()
{
    balance = 0;
    name = new char[1];
    strcpy(name, "");
    cout << "Account()\n";
}

Account::Account(double initialBalance, const char* accName)
{
    balance = initialBalance;
    name = new char[strlen(accName) + 1];
    strcpy(name, accName);
    cout << "Account(double)\n";
}

Account::Account(const Account& account)
{
    copyObject(account);

    cout << "Copy constructor\n";
}

void Account::deposit(double amount)
{
    balance += amount;
}

bool Account::withdraw(double amount)
{
    if (balance - amount < 0) {
        return false;
    }

    balance -= amount;
    return true;
}

double Account::getBalance() const
{
    return balance;
}

const char* Account::getName() const
{
    return name;
}

void Account::setName(const char* accName)
{
    delete [] name;

    name = new char[strlen(accName) + 1];
    strcpy(name, accName);
}

void Account::print() const
{
    cout << "Name: " << name << endl;
    cout << "Balance: " << balance << endl;
}

Account::~Account()
{
    delete [] name;
}

Account& Account::operator=(const Account& account)
{
    if (this != &account)
    {
        deleteObject();

        copyObject(account);
    }

    return *this;
}

void Account::deleteObject()
{
    delete [] name;
}

void Account::copyObject(const Account& account)
{
    name = new char[strlen(account.getName()) + 1];
    strcpy(name, account.getName());

    balance = account.balance;
}
