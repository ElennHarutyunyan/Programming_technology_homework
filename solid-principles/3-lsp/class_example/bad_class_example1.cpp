#include <iostream>

class Square {
public:
    virtual void setWidth(double w) {
        width = w;
    }
    virtual int getArea() {
        return static_cast<int>(width * width);
    }
protected:
    double width = 0;
};

class Rectangle : public Square {
public:
    virtual void setHeight(double h) {
        height = h;
    }
protected:
    double height = 0;
};

int main() {
    Rectangle rect;
    rect.setWidth(5);
    rect.setHeight(4);
    std::cout << "Option A compiled and ran successfully.\n";
    return 0;
}