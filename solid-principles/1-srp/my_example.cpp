#include <iostream>
#include <string>

// 1. Responsibility: Only manages the Car's physical state and properties
class Car {
private:
    std::string model;
    double fuelLevel;

public:
    Car(std::string m, double fuel) : model(m), fuelLevel(fuel) {}

    std::string getModel() const { return model; }
    double getFuelLevel() const { return fuelLevel; }
    
    void setFuelLevel(double fuel) { fuelLevel = fuel; }
};

// 2. Responsibility: Only handles Fuel Calculation and Refueling logic
class FuelManager {
public:
    void consumeFuel(Car& car, double amount) {
        double current = car.getFuelLevel();
        car.setFuelLevel(current - amount);
        std::cout << car.getModel() << " consumed " << amount << "L of fuel.\n";
    }
};

// 3. Responsibility: Only handles printing/reporting car status to the screen
class CarPrinter {
public:
    void printStatus(const Car& car) {
        std::cout << "[Report] Car: " << car.getModel() 
                  << " | Fuel Left: " << car.getFuelLevel() << "L\n";
    }
};

int main() {
    // Creating the car (Data & State)
    Car myCar("Tesla/BMW", 50.0);

    // Printing status using CarPrinter (SRP: Separate responsibility)
    CarPrinter printer;
    printer.printStatus(myCar);

    // Managing fuel using FuelManager (SRP: Separate responsibility)
    FuelManager fuelManager;
    fuelManager.consumeFuel(myCar, 12.5);

    // Printing updated status
    printer.printStatus(myCar);

    return 0;
}