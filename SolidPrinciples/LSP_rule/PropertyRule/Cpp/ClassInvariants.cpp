#include <bits/stdc++.h>
using namespace std;

// Class Invariant of a parent class Object should not be broken by child class Object.
// Hence child class can either maintain or strengthen the invariant but never narrows it down.

// Invariant : Balance cannot be negative

class BankAccount
{
protected:
    double balance;

public:
    BankAccount(double b)
    {
        if (b < 0)
            throw invalid_argument("Balance can't be negative");
        this->balance = b;
    }
    virtual void withdraw(double amount)
    {
        if (balance - amount < 0)
            throw runtime_error("Insufficinet funds");
        balance -= amount;
        cout << "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};

class CheatAccount : public BankAccount
{
public:
    CheatAccount(double b) : BankAccount(b) {}

    void withdraw(double amount) override
    {
        balance -= amount; // LSP break! Negative balance allowed
        cout << "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};

int main()
{
    BankAccount *bankAccount = new BankAccount(100);
    bankAccount->withdraw(100);

    BankAccount* cheatAccount=new CheatAccount(200);
    cheatAccount->withdraw(500);//breaking the rule
}