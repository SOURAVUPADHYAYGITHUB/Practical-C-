#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    string name;
    int accno;
    double balance;

public:
    // Constructors
    BankAccount() : name(""), accno(0), balance(0.0) {}
    BankAccount(string n, int a, double b) : name(n), accno(a), balance(b) {}

    // Input function
    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter account number: ";
        cin >> accno;
        cout << "Enter balance: ";
        cin >> balance;
    }

    // Withdraw function
    void withdraw(double x) {
        if (balance - x >= 500)
            balance -= x;
        else
            cout << "Unable to debit, the minimum balance should be 500" << endl;
    }

    // Deposit function
    void deposit(double x) {
        balance += x;
    }

    // Display function
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Account No: " << accno << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc;
    acc.input();
    acc.deposit(1000);
    acc.withdraw(200);
    acc.display();
    return 0;
}
