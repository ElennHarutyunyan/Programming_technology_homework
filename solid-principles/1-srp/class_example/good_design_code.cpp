#include <iostream>

class Screen {};

// 1. Responsibility: Pure Geometry and Data Storage only
class Circle {
public:
    explicit Circle(double rad) : radius(rad) {}

    double getRadius() const noexcept { return radius; }
    void setRadius(double rad) { radius = rad; }

private:
    double radius;
};

// 2. Responsibility: Render/Draw logic separated into its own class
class CircleRenderer {
public:
    void draw(const Circle& circle, Screen& screen) {
        std::cout << "Rendering Circle with radius " << circle.getRadius() << " on Screen.\n";
    }
};

// 3. Responsibility: Persistence/Serialization separated into its own class
class CircleSerializer {
public:
    void serialize(const Circle& circle) {
        std::cout << "Saving Circle (radius: " << circle.getRadius() << ") to database/stream.\n";
    }
};

int main() {
    // Each class now has a single, well-defined responsibility
    Circle myCircle(7.5);
    Screen screen;

    CircleRenderer renderer;
    renderer.draw(myCircle, screen);

    CircleSerializer serializer;
    serializer.serialize(myCircle);

    return 0;
}