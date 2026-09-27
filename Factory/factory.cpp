#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

struct Point
{
protected:
    Point(const float x, const float y) : x{x}, y{y} {}

public:
    float x, y; 
    static Point NewCartesian(float x, float y)
    {
        return {x, y};
    }
    static Point NewPolar(float r, float theta)
    {
        return {r * std::cos(theta), r * std::sin(theta)};
    }
};

int main()
{

    auto p1 = Point::NewCartesian(3.0f, 4.0f);
    std::cout << "Cartesian Point -> x: " << p1.x << ", y: " << p1.y << std::endl;

    auto p2 = Point::NewPolar(5.0f, M_PI_4);
    std::cout << "Polar Point     -> x: " << p2.x << ", y: " << p2.y << std::endl;

    return 0;
}