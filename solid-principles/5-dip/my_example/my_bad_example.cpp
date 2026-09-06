#include <iostream>

class SRAMMemory {
public:
    void readSRAM(int address) {
        std::cout << "Fetching data from SRAM at address 0x" << std::hex << address << "\n";
    }
};

class ProcessorCore {
private:
    SRAMMemory sram; 

public:
    void fetchInstruction(int address) {
        sram.readSRAM(address); 
    }
};

int main() {
    ProcessorCore cpu;
    cpu.fetchInstruction(0x0040);
    return 0;
}