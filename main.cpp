#include <iostream>
#include "account.h"
#include <cstring>

using namespace std;

bool isEmpty(Account account)
{
    return account.getBalance() <= 0;
}

void emptyAccount(Account account)
{
    account.withdraw(account.getBalance());
}

Account emptyBetterAccount(Account account)
{
    account.withdraw(account.getBalance());
    return account;
}

int main()
{
    Account myAccount(500, "current account");

    myAccount.deposit(200);

    //emptyAccount(myAccount);

    //copy constructor called
    Account thirdAccount;

    //copy constructor NOT called
    //Account fourthAccount;
    //fourthAccount = myAccount;

    //emptyBetterAccount(thirdAccount);

    thirdAccount.setName("deposit account");

    thirdAccount = myAccount;

    cout << endl;
    thirdAccount.print();
    cout << endl;

    return 0;
}
