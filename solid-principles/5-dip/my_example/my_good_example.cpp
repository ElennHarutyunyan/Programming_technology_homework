#include <iostream>
#include <memory>

class IMemory {
public:
    virtual ~IMemory() = default;
    virtual void read(int address) = 0;
};

class SRAMMemory : public IMemory {
public:
    void read(int address) override {
        std::cout << "Reading from SRAM interface at 0x" << std::hex << address << "\n";
    }
};

class DRAMMemory : public IMemory {
public:
    void read(int address) override {
        std::cout << "Reading from DRAM interface (with latency cycles) at 0x" << std::hex << address << "\n";
    }
};

class ProcessorCore {
private:
    IMemory& memory;

public:
    explicit ProcessorCore(IMemory& mem) : memory(mem) {}

    void fetchInstruction(int address) {
        memory.read(address);
    }
};

int main() {
    SRAMMemory sram;
    DRAMMemory dram;

    ProcessorCore cpuWithSRAM(sram);
    cpuWithSRAM.fetchInstruction(0x1000);

    std::cout << "-----------------\n";

    ProcessorCore cpuWithDRAM(dram);
    cpuWithDRAM.fetchInstruction(0x2000);

    return 0;
}