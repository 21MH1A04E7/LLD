#include <bits/stdc++.h>
using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class BasicBurger:public Burger{
public:
    void prepare(){
        cout<<"Preparing Basic Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandarBurger:public Burger{
public:
    void prepare(){
         cout << "Preparing Standard Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumBurger:public Burger{
public:
    void prepare(){
        cout << "Preparing Premium Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};

class BurgerFactory{
public:
    Burger* createBurger(string &type){
        if(type=="basic"){
            return new BasicBurger();
        }else if(type=="standard"){
            return new StandarBurger();
        }else if(type=="premium"){
            return new PremiumBurger();
        }else {
            cout<<"Invalid Burger type "<<endl;
            return nullptr;
        }
    }
};
int main()
{
    string type1="standard";
    BurgerFactory* myBurgerFactory=new BurgerFactory();
    Burger* burger1=myBurgerFactory->createBurger(type1);
    burger1->prepare();

    string type2="premium";
    Burger* burger2=myBurgerFactory->createBurger(type2);
    burger2->prepare();

}