#include <iostream>

// Mock classes for dependencies
class Screen {};
class Printer {};
class ByteStream {};
class Vector3D {};
class Quaternion {};

// VIOLATION OF SINGLE RESPONSIBILITY PRINCIPLE (SRP)
// This class has multiple reasons to change:
// 1. Geometry changes (radius, translate, rotate)
// 2. Screen/Printer rendering changes
// 3. Serialization format changes
class Circle {
public:
    explicit Circle(double rad) : radius(rad) {}

    double getRadius() const noexcept { return radius; }

    // Geometry responsibility
    void translate(Vector3D const&) {
        std::cout << "Translating circle...\n";
    }
    void rotate(Quaternion const&) {
        std::cout << "Rotating circle...\n";
    }

    // Drawing responsibility (Should not be here!)
    void draw(Screen& s) {
        std::cout << "Drawing Circle on Screen. Radius: " << radius << "\n";
    }
    void draw(Printer& p) {
        std::cout << "Drawing Circle on Printer. Radius: " << radius << "\n";
    }

    // Persistence responsibility (Should not be here!)
    void serialize(ByteStream& bs) {
        std::cout << "Serializing Circle data...\n";
    }

private:
    double radius;
};

int main() {
    Circle myCircle(5.0);
    Screen screen;
    myCircle.draw(screen);
    return 0;
}