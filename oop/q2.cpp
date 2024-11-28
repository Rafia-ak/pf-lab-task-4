#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber;
    string accountHolderName;
    double balance;
    string transactionHistory;

public:
    Account(string accNumber, string accHolderName, double initialBalance) 
        : accountNumber(accNumber), accountHolderName(accHolderName), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory += "Deposited: $" + to_string(amount) + "\n";
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactionHistory += "Withdrawn: $" + to_string(amount) + "\n";
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }

    void displayTransactionHistory() {
        cout << "Transaction History for Account " << accountNumber << ":\n" << transactionHistory;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string accNumber, string accHolderName, double initialBalance, double interestRate) 
        : Account(accNumber, accHolderName, initialBalance), interestRate(interestRate) {}

    void calculateInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        transactionHistory += "Interest earned: $" + to_string(interest) + "\n";
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(string accNumber, string accHolderName, double initialBalance, double overdraftLimit) 
        : Account(accNumber, accHolderName, initialBalance), overdraftLimit(overdraftLimit) {}

    void withdraw(double amount) override {
        if (amount > 0 && amount <= (balance + overdraftLimit)) {
            balance -= amount;
            transactionHistory += "Withdrawn: $" + to_string(amount) + "\n";
        } else {
            cout << "Overdraft limit exceeded or insufficient funds!" << endl;
        }
    }
};

int main() {
    SavingsAccount savings("SA001", "Rafia Abdul Karim", 2000.0, 3.0);
    CurrentAccount current("CA001", "Rafia Abdul Karim", 500.0, 200.0);

    savings.deposit(500.0);
    savings.withdraw(400.0);
    savings.calculateInterest();

    current.deposit(400.0);
    current.withdraw(800.0);
    current.withdraw(400.0);

    cout << "\nSavings Account Details:\n";
    savings.displayDetails();
    savings.displayTransactionHistory();

    cout << "\nCurrent Account Details:\n";
    current.displayDetails();
    current.displayTransactionHistory();

    return 0;
}
