#include<bits/stdc++.h>
using namespace std;

//Product 1--> Burger
class Burger {
public:
    virtual void prepare() = 0;  // Pure virtual function
};

class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};

class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Wheat Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Wheat Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Wheat Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};

//Product 2 --> GarlicBread
class GarlicBread{
public:
    virtual void prepare()=0;
};

class BasicGarlicBread : public GarlicBread {
public:
    void prepare() override {
        std::cout << "Preparing Basic Garlic Bread with butter and garlic!\n";
    }
};

class CheeseGarlicBread : public GarlicBread {
public:
    void prepare() override {
        std::cout << "Preparing Cheese Garlic Bread with extra cheese and butter!\n";
    }
};

class BasicWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        std::cout << "Preparing Basic Wheat Garlic Bread with butter and garlic!\n";
    }
};

class CheeseWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        std::cout << "Preparing Cheese Wheat Garlic Bread with extra cheese and butter!\n";
    }
};

// Factory and its concretions
class MealFactory{
public:
    virtual Burger* createBurger(string& type)=0;
    virtual GarlicBread* createGarlicBread(string& type) = 0;
};
class SinghBurger : public MealFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        } else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(string& type) override {
        if (type == "basic") {
            return new BasicGarlicBread();
        } else if (type == "cheese") {
            return new CheeseGarlicBread();
        } 
        else {
            cout << "Invalid Garlic bread type! " << endl;
            return nullptr;
        }
    }
};

class KingBurger : public MealFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic") {
            return new BasicWheatBurger();
        } else if (type == "standard") {
            return new StandardWheatBurger();
        } else if (type == "premium") {
            return new PremiumWheatBurger();
        } else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(string& type) override {
        if (type == "basic") {
            return new BasicWheatGarlicBread();
        } else if (type == "cheese") {
            return new CheeseWheatGarlicBread();
        } 
        else {
            cout << "Invalid Garlic bread type! " << endl;
            return nullptr;
        }
    }
};



int main(){
    string burgerType1="basic";
    string garlicBreadType1="cheese";

    MealFactory* mealFactor1=new KingBurger();
    Burger* burger1=mealFactor1->createBurger(burgerType1);
    GarlicBread* garlicBread1=mealFactor1->createGarlicBread(garlicBreadType1);
    burger1->prepare();
    garlicBread1->prepare();

    
}