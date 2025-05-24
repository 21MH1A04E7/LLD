#include<bits/stdc++.h>
using namespace std;

// A Precondition must be statisfied before a method can be executed.
// Sub classes can weaken the precondition but cannot strengthen it.

class User{
public:
    // Precondition: Password must be at least 8 characters long
    virtual void setPassword(string password){
        if(password.length()<8){
            throw invalid_argument("Password must be at least 8 character long!");
        }
        cout<<"Password set successfully"<<endl;
    }
};

class AminUser:public User{
public:
    // Precondition: Password must be at least 6 characters
    void setPassword(string password){
        if(password.length()<6)
        throw invalid_argument("Password must be at least 6 character long!");
        cout<<"Password set successfully"<<endl;
  }
};
int main(){
    User* user=new AminUser();
    try{
        user->setPassword("hariom");// Works fine: AdminUser allows shorter passwords
    }catch(invalid_argument &e){
        cout<<e.what()<<endl;
    }

}