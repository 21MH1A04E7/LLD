//Product Class (product)
class Product{
    constructor(name,price){
        this.name=name;
        this.price=price;
    }
}

//only handl the price
class ProductCart{
    constructor(){
        this.productList=[];
    }
    addProduct(product){
        this.productList.push(product);
    }
    clacPrice(){
        const price=this.productList.reduce((accumulator,item)=>{
            return accumulator+item.price;
        },0)
        console.log("product price : ",price);
    }
    getProduct(){
        return this.productList;
    }
}

//2 handle print invoice logic

class ProductCartPrinter{
    constructor(productCart){
        this.productCart=productCart;
    }
    printInvoice(){
        let productList=this.productCart.getProduct();
        productList.forEach((item)=>console.log(item.name))
    }
}

//3 handle save in db

class ProductStorage{
    constructor(productCart){
        this.productCart=productCart;
    }
    Save(){
       console.log("saving all the product in the database");
    }
}


const cart1=new ProductCart();

const product1=new Product("apple",30);
const product2=new Product("banana",40);

cart1.addProduct(product1);
cart1.addProduct(product2);
cart1.clacPrice();

const invoice=new ProductCartPrinter(cart1);
invoice.printInvoice();

const saveDb=new ProductStorage(cart1);
saveDb.Save();


//it's is following single responsibility principle
//each class have only one reason to change
