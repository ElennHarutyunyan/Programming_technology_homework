#include <iostream>

class Shape {
public:
    virtual double getArea() const = 0; 
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    void setWidth(double w) { width = w; }
    void setHeight(double h) { height = h; }

private:
    double width;
    double height;
};

class Square : public Shape {
public:
    explicit Square(double s) : side(s) {}

    double getArea() const override {
        return side * side;
    }

    void setSide(double s) { side = s; }

private:
    double side;
};

int main() {
    Rectangle rect(5.0, 4.0);
    Square sq(4.0);

    std::cout << "Rectangle Area: " << rect.getArea() << "\n";
    std::cout << "Square Area: " << sq.getArea() << "\n";

    return 0;
}