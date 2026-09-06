#include <iostream>


class ISwitchable {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~ISwitchable() = default;
};

class IRecorder {
public:
    virtual void recordVideo() = 0;
    virtual ~IRecorder() = default;
};

class IColorable {
public:
    virtual void changeColor() = 0;
    virtual ~IColorable() = default;
};

class SmartBulb : public ISwitchable, public IColorable {
public:
    void turnOn() override {
        std::cout << "Smart Bulb is ON.\n";
    }
    
    void turnOff() override {
        std::cout << "Smart Bulb is OFF.\n";
    }

    void changeColor() override {
        std::cout << "Smart Bulb color changed to Warm White.\n";
    }
};


class SecurityCamera : public ISwitchable, public IRecorder {
public:
    void turnOn() override {
        std::cout << "Security Camera is active.\n";
    }
    
    void turnOff() override {
        std::cout << "Security Camera is shut down.\n";
    }

    void recordVideo() override {
        std::cout << "Security Camera is recording footage...\n";
    }
};

int main() {
    SmartBulb bulb;
    bulb.turnOn();
    bulb.changeColor();

    std::cout << "-----------------\n";

    SecurityCamera camera;
    camera.turnOn();
    camera.recordVideo();

    std::cout << "Good design compiled successfully without forced empty stubs.\n";
    return 0;
}