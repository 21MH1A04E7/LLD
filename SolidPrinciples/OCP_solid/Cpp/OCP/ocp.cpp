#include<bits/stdc++.h>
using namespace std;

//product class represent any item of any Ecommerce.
class Product{
    public:
    double price;
    string name;
    Product(string name,double price){
        this->name=name;
        this->price=price;
    }
};

//Voilating SRP: Shopping card handling multiple responsibilites
class ShoppingCart{
    private:
    vector<Product*>products;
    public:
    void addProduct(Product *p){
        products.push_back(p);
    }
    const vector<Product*>& getProducts(){
        return products;
    }
    //1. Calculates total price in cart.
    double calculateTotal(){
        double total=0;
        for(auto p:products){
            total+=p->price;
        }
        return total;
    }
};

//2. only reponsible for the printing the invoice
class ShopingCartPrinter{
    private:
    ShoppingCart* cart;
    public:
    ShopingCartPrinter(ShoppingCart* cart){
        this->cart=cart;
    }
    void printInvoice(){
        cout<<"Shoping cart Invoice "<<endl;
        for(auto p:cart->getProducts()){
            cout<<p->name<<" -$"<<p->price<<endl;
        }
        cout<<"Total: $"<<cart->calculateTotal()<<endl;
    }
};

// Abstract class
class Persistence{
    private:
    ShoppingCart * cart;
    public:
    virtual void save(ShoppingCart* cart)=0;
};

class SQLPersistence:public Persistence{
    public:
    void save(ShoppingCart* cart){
        cout<<"Saving shopping cart to sql DB..."<<endl;
    }
};

class MongoPersistence:public Persistence{
    public:
    void save(ShoppingCart* cart){
        cout<<"Saving shopping cart to mongo DB..."<<endl;
    }
};

class FilePersistence:public Persistence{
    public:
    void save(ShoppingCart* cart){
        cout<<"Saving shopping cart to file ..."<<endl;
    }
};

int main(){
    ShoppingCart *cart=new ShoppingCart();
    cart->addProduct(new Product("mango",20.2));
    cart->addProduct(new Product("pizza",12.5));
    cout<<cart->calculateTotal()<<endl;

    ShopingCartPrinter* printer=new ShopingCartPrinter(cart);
    printer->printInvoice();

    Persistence* sql=new SQLPersistence();
    sql->save(cart);

    Persistence* mongo=new MongoPersistence();
    mongo->save(cart);

    Persistence* file=new FilePersistence();
    file->save(cart);
    
}