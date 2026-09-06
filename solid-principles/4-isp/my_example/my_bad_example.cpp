#include <iostream>

class ISmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void recordVideo() = 0;   
    virtual void changeColor() = 0;  
    virtual ~ISmartDevice() = default;
};

class SmartBulb : public ISmartDevice {
public:
    void turnOn() override {
        std::cout << "Smart Bulb is ON.\n";
    }
    
    void turnOff() override {
        std::cout << "Smart Bulb is OFF.\n";
    }

    void changeColor() override {
        std::cout << "Smart Bulb color changed to Blue.\n";
    }

    void recordVideo() override {
        std::cout << "Error: Smart Bulb cannot record video!\n";
    }
};

int main() {
    SmartBulb bulb;
    bulb.turnOn();
    bulb.recordVideo(); 
    return 0;
}