#include <iostream>
#include <vector>
#include <memory>


class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0; 
};

class Circle : public Shape {
public:
    explicit Circle( double rad ) : radius{ rad } {}
    void draw() const override {
        std::cout << "Drawing a Circle with radius: " << radius << '\n';
    }
private:
    double radius;
};

class Square : public Shape {
public:
    explicit Square( double s ) : side{ s } {}
    void draw() const override {
        std::cout << "Drawing a Square with side: " << side << '\n';
    }
private:
    double side;
};


void drawShapes( std::vector<std::unique_ptr<Shape>> const& shapes ) {
    for ( auto const& s : shapes ) {
        s->draw(); 
    }
}

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back( std::make_unique<Circle>( 5.0 ) );
    shapes.push_back( std::make_unique<Square>( 4.0 ) );

    drawShapes( shapes );
    return 0;
}