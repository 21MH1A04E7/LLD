#include<bits/stdc++.h>
using namespace std;


// Subsystems
class PowerSupply {
public:
    void providePower() {
        cout << "Power Supply: Providing power..." << endl;
    }
};
class CoolingSystem {
public:
    void startFans() {
        cout << "Cooling System: Fans started..." << endl;
    }
};
class CPU {
public:
    void initialize() {
        cout << "CPU: Initialization started..." << endl;
    }
};


class Memory {
public:
    void selfTest() {
        cout << "Memory: Self-test passed..." << endl;
    }
};

class HardDrive {
public:
    void spinUp() {
        cout << "Hard Drive: Spinning up..." << endl;
    }
};

class BIOS {
public:
    void boot(CPU& cpu, Memory& memory) {
        cout << "BIOS: Booting CPU and Memory checks..." << endl;
        cpu.initialize();
        memory.selfTest();
    }
};

class OperatingSystem {
public:
    void load() {
        cout << "Operating System: Loading into memory..." << endl;
    }
};

//Facade

class ComputerFacade{
private: 
    PowerSupply power;
     CoolingSystem cool;
     CPU cpu;
     Memory memory;
     HardDrive hard;
     BIOS bios;
     OperatingSystem ops;
public:    void startComputer(){
        cout<<"<----------------- Computer starting ------------->"<<endl;
        power.providePower();
        cool.startFans();
        cpu.initialize();
        memory.selfTest();
        hard.spinUp();
        bios.boot(cpu,memory);
        ops.load();
        cout<<"<--------------- Computer started -------------->"<<endl;
    }

};

//Client
int main(){
    ComputerFacade computer;
    computer.startComputer();
    return 0;

}