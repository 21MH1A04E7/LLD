#include <bits/stdc++.h>
using namespace std;

class Account
{
public:
    virtual void deposite(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account
{
private:
    double balance;

public:
    SavingAccount()
    {
        balance = 0;
    }
    void deposite(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in Saving Account new balance: " << balance << endl;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdraw: " << amount << " from saving account new balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in saving account" << endl;
        }
    }
};
class CurrentAccount : public Account
{
private:
    double balance;

public:
    CurrentAccount()
    {
        balance = 0;
    }
    void deposite(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in Saving Current new balance: " << balance << endl;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdraw: " << amount << " from Current account new balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in Current account" << endl;
        }
    }
};
class FixedTermAccount : public Account
{
private:
    double balance;

public:
    FixedTermAccount()
    {
        balance = 0;
    }
    void deposite(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in FixedTerm Account new balance: " << balance << endl;
    }
    void withdraw(double amount)
    {
        throw logic_error("Withdrawal not allowed in Fixed Term Account");
    }
};

class BankClient
{
private:
    vector<Account *> accounts;
public:
    BankClient(vector<Account*> accounts){
        this->accounts=accounts;
    }
    void processTransactions(){
        for(Account *acc:accounts){
            acc->deposite(1000);//all account allow deposits

            //Assuming all accounts support withdrawal (LSP Violation)
            try{
                acc->withdraw(500);
            }catch(const logic_error& e){
                cout<<"Excepiton: "<<e.what()<<endl;
            }
        }
    }
};
int main()
{
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient* client=new BankClient(accounts);
    client->processTransactions();//thow exceptions when withdrawing from FixedTermAccount
    
}