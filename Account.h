#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Account {
protected:
    string ownerName;
    double balance;

public:
    Account(const string& ownerName = "", double balance = 0.0)
            : ownerName(ownerName), balance(balance) {}

    double getBalance() const {
        return balance;
    }

    virtual void display() const {
        cout << "Owner: " << ownerName << "\n";
        cout << "Balance: " << balance << "\n";
    }

    virtual ~Account() = default;

    Account operator+(const Account &other) const {
        return Account(ownerName + " & " + other.ownerName, balance + other.balance);
    }

    Account operator-(const Account &other) const {
        return Account(ownerName, balance - other.balance);
    }

    bool operator==(const Account &other) const {
        return balance == other.balance;
    }

    friend istream& operator>>(istream &in, Account &obj) {
        getline(in, obj.ownerName);
        in >> obj.balance;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        return in;
    }

    friend ostream& operator<<(ostream &out, const Account &obj) {
        out << "Owner: " << obj.ownerName << "\n";
        out << "Balance: " << obj.balance << "\n";
        return out;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const string& ownerName = "", double balance = 0.0, double interestRate = 0.0)
            : Account(ownerName, balance), interestRate(interestRate) {}

    void display() const override {
        cout << "Owner: " << ownerName << "\n";
        cout << "Balance: " << balance << "\n";
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(const string& ownerName = "", double balance = 0.0, double transactionFee = 0.0)
            : Account(ownerName, balance), transactionFee(transactionFee) {}

    void display() const override {
        cout << "Owner: " << ownerName << "\n";
        cout << "Balance: " << balance << "\n";
        cout << "Transaction Fee: " << transactionFee << "\n";
    }
};

#endif
