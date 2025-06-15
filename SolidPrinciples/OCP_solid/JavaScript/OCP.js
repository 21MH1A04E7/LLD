// Product class
class Product {
  constructor(name, price) {
    this.name = name;
    this.price = price;
  }
}

// ShoppingCart class - Handles product operations and total calculation
class ShoppingCart {
  constructor() {
    this.products = [];
  }

  addProduct(product) {
    this.products.push(product);
  }

  getProducts() {
    return this.products;
  }

  calculateTotal() {
    return this.products.reduce((total, product) => total + product.price, 0);
  }
}

// ShoppingCartPrinter - Only prints invoice
class ShoppingCartPrinter {
  constructor(cart) {
    this.cart = cart;
  }

  printInvoice() {
    console.log("Shopping Cart Invoice:");
    this.cart.getProducts().forEach((product) => {
      console.log(`${product.name} - $${product.price}`);
    });
    console.log(`Total: $${this.cart.calculateTotal()}`);
  }
}

// Abstract class for Persistence
class Persistence {
  save(cart) {
    throw new Error("This method should be overridden.");
  }
}

// SQL persistence implementation
class SQLPersistence extends Persistence {
  save(cart) {
    console.log("Saving shopping cart to SQL DB...");
    // Simulated logic
  }
}

// MongoDB persistence implementation
class MongoPersistence extends Persistence {
  save(cart) {
    console.log("Saving shopping cart to Mongo DB...");
    // Simulated logic
  }
}

// File persistence implementation
class FilePersistence extends Persistence {
  save(cart) {
    console.log("Saving shopping cart to File...");
    // Simulated logic
  }
}

// === USAGE ===
const cart = new ShoppingCart();
cart.addProduct(new Product("mango", 20.2));
cart.addProduct(new Product("pizza", 12.5));
console.log("Total:", cart.calculateTotal());

const printer = new ShoppingCartPrinter(cart);
printer.printInvoice();

const sqlPersistence = new SQLPersistence();
sqlPersistence.save(cart);

const mongoPersistence = new MongoPersistence();
mongoPersistence.save(cart);

const filePersistence = new FilePersistence();
filePersistence.save(cart);
