#include<bits/stdc++.h>
using namespace std;

//Component Interface: define a common interface for Coffie
class Coffee{
public:
    virtual string getDescription()=0;
    virtual int getCost()=0;
    virtual ~Coffee(){}//Virtual destructor
};

//Concrete Component: SimpleCoffee 
class SimpleCoffee:public Coffee{
    public:
    string getDescription(){
        return "This is Simple Coffee";
    }
    int getCost(){
        return 5;
    }
};

//Abstract Decorator: "is-a " and "has-a"
class CoffeeDecorator:public Coffee{
protected:
    Coffee* coffeeDecorator;//wrapped component
public:
    CoffeeDecorator(Coffee* c){
        this->coffeeDecorator=c;
    }
};

class MilkDecorator:public CoffeeDecorator{
public:
    MilkDecorator(Coffee* c):CoffeeDecorator(c){}

    string getDescription(){
        return coffeeDecorator->getDescription()+" with Milk";
    }
    int getCost(){
        return coffeeDecorator->getCost()+2;
    }
};

class SugarDecorator:public CoffeeDecorator{
public:
    SugarDecorator(Coffee* c):CoffeeDecorator(c){}

    string getDescription(){
        return coffeeDecorator->getDescription()+" with Sugar";
    }
    
    int getCost(){
        return coffeeDecorator->getCost()+3;
    }
};

int main(){
    Coffee* coffee1=new SimpleCoffee();
    cout<<coffee1->getDescription()<<endl;
    cout<<coffee1->getCost()<<endl;
    
    //decorator with milk
    coffee1=new SugarDecorator(coffee1);
    cout<<coffee1->getDescription()<<endl;
    cout<<coffee1->getCost()<<endl;// 5+3

    coffee1=new MilkDecorator(coffee1);
    cout<<coffee1->getDescription()<<endl;
    cout<<coffee1->getCost()<<endl;
}