#include <iostream>
#include <cassert>

class Rectangle {
public:
    virtual void setWidth(double w) { width = w; }
    virtual void setHeight(double h) { height = h; }
    virtual int getArea() { return static_cast<int>(width * height); }
protected:
    double width = 0;
    double height = 0;
};

class Square : public Rectangle {
public:
    void setWidth(double w) override {
        Rectangle::setWidth(w);
        Rectangle::setHeight(w);
    }
    void setHeight(double h) override {
        Rectangle::setWidth(h);
        Rectangle::setHeight(h);
    }
};

void resize(Rectangle& r) {
    r.setWidth(5);
    r.setHeight(4); 
}

int main() {
    Square sq;
    resize(sq);
    std::cout << "Option B compiled successfully.\n";
    return 0;
}