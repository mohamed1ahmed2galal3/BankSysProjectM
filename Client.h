#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include<vector>
class Client : public Person {
private:
    double balance;
public:
    Client() : Person(), balance(1500.0) { id = -1; }
    Client(const string& name, const string& password, double balance)
        : Person(name, password) {
        setBalance(balance);
    }
    void setBalance(double balance) {
        if (Validator::isValidBalance(balance))
            this->balance = balance;
        else
            cout << "Invalid balance! Minimum is 1500.\n";
    }
    double getBalance() const { return balance; }
    void checkBalance() const {
        cout << "Your current balance is: " << balance << endl;
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
        }
        else {
            cout << "Invalid deposit amount!\n";
        }
    }
    void withdraw(double amount) {
        if (amount > 0 && balance - amount >= 1500) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
        }
        else {
            cout << "Invalid withdrawal amount or insufficient balance!\n";
        }
    }
    void transferTo(double amount, Client& recipient) {
        if (&recipient == this) {
            cout << "Error: You cannot transfer money to yourself!\n";
            return;
        }
        if (amount > 0 && balance - amount >= 1500) {
            balance -= amount;
            recipient.deposit(amount);
            cout << "Transferred: " << amount << " to " << recipient.getName() << ". Your New Balance: " << balance << endl;
        }
        else {
            cout << "Invalid transfer amount or insufficient balance!\n";
        }
    }
    void Display() const override {
        cout << "===== Client =====\n";
        cout << "ID         = " << id << "\n";
        cout << "Name       = " << name << "\n";
        cout << "Balance    = " << balance << "\n";
        cout << "=================\n";
    }
};

static vector<Client> Clients;
static vector<Client> ::iterator clit;

#endif // CLIENT_H
