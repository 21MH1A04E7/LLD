// Subsystems
class PowerSupply {
  providePower() {
    console.log("Power Supply: Providing power...");
  }
}

class CoolingSystem {
  startFans() {
    console.log("Cooling System: Fans started...");
  }
}

class CPU {
  initialize() {
    console.log("CPU: Initialization started...");
  }
}

class Memory {
  selfTest() {
    console.log("Memory: Self-test passed...");
  }
}

class HardDrive {
  spinUp() {
    console.log("Hard Drive: Spinning up...");
  }
}

class BIOS {
  boot(cpu, memory) {
    console.log("BIOS: Booting CPU and Memory checks...");
    cpu.initialize();
    memory.selfTest();
  }
}

class OperatingSystem {
  load() {
    console.log("Operating System: Loading into memory...");
  }
}

// Facade
class ComputerFacade {
  constructor() {
    this.power = new PowerSupply();
    this.cool = new CoolingSystem();
    this.cpu = new CPU();
    this.memory = new Memory();
    this.hard = new HardDrive();
    this.bios = new BIOS();
    this.ops = new OperatingSystem();
  }

  startComputer() {
    console.log("<----------------- Computer starting ------------->");
    this.power.providePower();
    this.cool.startFans();
    this.cpu.initialize();
    this.memory.selfTest();
    this.hard.spinUp();
    this.bios.boot(this.cpu, this.memory);
    this.ops.load();
    console.log("<--------------- Computer started -------------->");
  }
}

// Client
const computer = new ComputerFacade();
computer.startComputer();
