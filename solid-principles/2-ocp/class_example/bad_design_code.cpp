#include <iostream>
#include <vector>
#include <memory>

enum ShapeType { circle, square };

class Shape {
public:
    explicit Shape( ShapeType t ) : type{ t } {}
    ShapeType getType() const noexcept { return type; }
    virtual ~Shape() = default;
private:
    ShapeType type;
};

class Circle : public Shape {
public:
    explicit Circle( double rad ) : Shape{ circle }, radius{ rad } {}
    double getRadius() const noexcept { return radius; }
private:
    double radius;
};

class Square : public Shape {
public:
    explicit Square( double s ) : Shape{ square }, side{ s } {}
    double getSide() const noexcept { return side; }
private:
    double side;
};

void drawCircle( Circle const& c ) {
    std::cout << "Drawing a Circle with radius: " << c.getRadius() << '\n';
}

void drawSquare( Square const& s ) {
    std::cout << "Drawing a Square with side: " << s.getSide() << '\n';
}

// bad_design Switch-case և static_cast 
void drawShapes( std::vector<std::unique_ptr<Shape>> const& shapes ) {
    for ( auto const& s : shapes ) {
        switch ( s->getType() ) {
            case circle:
                drawCircle( *static_cast<Circle const*>( s.get() ) );
                break;
            case square:
                drawSquare( *static_cast<Square const*>( s.get() ) );
                break;
        }
    }
}

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Square>(4.0));

    drawShapes(shapes);
    return 0;
}