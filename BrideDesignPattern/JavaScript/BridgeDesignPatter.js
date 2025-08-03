// Engine Interface
class Engine {
  start() {
    throw new Error("start() must be implemented");
  }
}

// Concrete Engines
class PetrolEngine extends Engine {
  start() {
    console.log("Petrol engine starting with ignition!");
  }
}

class DieselEngine extends Engine {
  start() {
    console.log("Diesel engine roaring to life!");
  }
}

class ElectricEngine extends Engine {
  start() {
    console.log("Electric engine powering up silently!");
  }
}

// Car Base Class
class Car {
  constructor(engine) {
    this.engine = engine;
  }

  drive() {
    throw new Error("drive() must be implemented");
  }
}

// Sedan Class
class Sedan extends Car {
  constructor(engine) {
    super(engine);
  }

  drive() {
    this.engine.start();
    console.log("Driving a Sedan on the highway.");
  }
}

// SUV Class
class SUV extends Car {
  constructor(engine) {
    super(engine);
  }

  drive() {
    this.engine.start();
    console.log("Driving an SUV off-road.");
  }
}

// Usage
const petrolEngine = new PetrolEngine();
const dieselEngine = new DieselEngine();
const electricEngine = new ElectricEngine();

const mySedan = new Sedan(petrolEngine);
const mySUV = new SUV(electricEngine);
const yourSUV = new SUV(dieselEngine);

mySedan.drive();   // Petrol engine + Sedan
mySUV.drive();     // Electric engine + SUV
yourSUV.drive();   // Diesel engine + SUV
