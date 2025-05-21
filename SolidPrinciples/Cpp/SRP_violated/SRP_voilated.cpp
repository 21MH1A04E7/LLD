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
    //2.Violating SRP - prints invoice (should be in a sperate class)
    void printInvoice(){
        cout<<"Shopping Cart Invoice"<<endl;
        for(auto p:products){
            cout<<p->name<<" -$"<<p->price<<endl;
        }
        cout<<"Total: $"<<calculateTotal()<<endl;
    }
    //3.Voilating SRP - Saves in db (should be in a sperate class)
    void saveToDatabase(){
        cout<<"Saving shopping cart to databaes...."<<endl;
    }

};
int main(){
    ShoppingCart *cart=new ShoppingCart();
    cart->addProduct(new Product("mango",20.2));
    cart->addProduct(new Product("pizza",12.5));
    cout<<"total price "<<cart->calculateTotal()<<endl;
    cart->printInvoice();
    cart->saveToDatabase();

}