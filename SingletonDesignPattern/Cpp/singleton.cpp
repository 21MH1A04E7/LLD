#include<bits/stdc++.h>
#include <mutex>
using namespace std;

class Singleton{
private:
    static Singleton* instance;
    // static mutex mtx;//help to lock
    Singleton(){
        cout<<"singleton constructor"<<endl;
    }
public:
    static Singleton* getInstance(){
        if(instance==nullptr){
            // lock_guard<mutex> lock(mtx);//lock for thread
            if(instance==nullptr){
                instance=new Singleton();
            }
        }
        return instance;
    }
};

Singleton* Singleton::instance=nullptr;// we should declared outside of class in cpp
int main(){
    Singleton* s1=Singleton::getInstance();
    Singleton* s2=Singleton::getInstance();
    cout<<(s1==s2)<<endl;
}