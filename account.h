#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private:
    double balance;
    char* name;

    void copyObject(const Account& account);
    void deleteObject();
public:
    Account();
    Account(double initialBalance, const char* accName);
    Account(const Account& account);
    ~Account();
    Account& operator=(const Account& account);

    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;

    void setName(const char* accName);
    const char* getName() const;

    void print() const;
};

#endif // ACCOUNT_H
