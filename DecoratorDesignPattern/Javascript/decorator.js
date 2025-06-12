class Coffee{
    geDescription(){
        throw new Error("Method not implemented");
    }
    getCost(){
        throw new Error("Method not implemented");
    }
}

class SimpleCoffee extends Coffee{
    geDescription(){
        return "This is Simple Coffee";
    }
    getCost(){
        return 5;
    }
}

class CoffeeDecorator extends Coffee{
    constructor(coffee){
        super(coffee);
        this.coffeeDecorator=coffee;
    }
    geDescription(){
        return this.coffeeDecorator.geDescription();
    }
    getCost(){
        return history.coffeeDecorator.getCost();
    }
}

class MilkDecorator extends CoffeeDecorator{
    constructor(coffee){
        super(coffee);
    }
    geDescription(){
        return this.coffeeDecorator.geDescription()+" With Milk";
    }
    getCost(){
        return this.coffeeDecorator.getCost()+3;
    }
}

class SugarDecorator extends CoffeeDecorator{
    constructor(coffee){
        super(coffee);
    }
    geDescription(){
        return this.coffeeDecorator.geDescription()+" With Sugar";
    }
    getCost(){
        return this.coffeeDecorator.getCost()+6;
    }
}


let coffee=new SimpleCoffee();
console.log(coffee.geDescription());
console.log(coffee.getCost());

coffee=new MilkDecorator(coffee);
console.log(coffee.geDescription());
console.log(coffee.getCost());

coffee=new SugarDecorator(coffee);
console.log(coffee.geDescription());
console.log(coffee.getCost());


