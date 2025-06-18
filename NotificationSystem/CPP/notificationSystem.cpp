//*--------------------
#include<bits/stdc++.h>
using namespace std;

class INofication{
    public:
    virtual string getContent() const=0;
    virtual ~INofication(){}
};

class SimpleNotification:public INofication{
private:
    string text;
public:
    SimpleNotification(string text){
        this->text=text;
    }
    string getContent(){
        return this->text;
    }
};

class INotificationDecorator:public INofication{
protected:
    INofication* notification;
public:
    INotificationDecorator(INofication* notification){
        this->notification=notification;
    }
    virtual ~INotificationDecorator(){}
};

class TimestampDecorator:public INotificationDecorator{
public:
    TimestampDecorator(INofication* n):INotificationDecorator(n){}
    string getContent(){
        return "[2024-03-12 12:34:00]"+notification->getContent();
    }
};

class SignatureDecorator:public INotificationDecorator{
private:
    string signature;
public:
    SignatureDecorator(INofication* n,const string &sig):INotificationDecorator(n){
        this->signature=sig;
    }
    string getContent(){
        return "&*(&**(*&(*&*($%)))) "+notification->getContent();
    }
};



class IObserver{
public:
    virtual void update()=0;
};

class IObservable{
public:
    virtual void addObserver(IObserver* observer)=0;
    virtual void addObserver(IObserver* observer)=0;
    virtual void notifyObserver()=0;
};
int main(){

}

