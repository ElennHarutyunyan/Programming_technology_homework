#include <iostream>
#include <cassert>


class Rook {
public:
    virtual void setPosition(int x, int y) {
        currentX = x;
        currentY = y;
        std::cout << "Rook moved straight to (" << currentX << ", " << currentY << ")\n";
    }
    
    int getX() const { return currentX; }
    int getY() const { return currentY; }

protected:
    int currentX = 0;
    int currentY = 0;
};

class Queen : public Rook {
public:

    void setPosition(int x, int y) override {
        currentX = x;
        currentY = y;
        std::cout << "Queen moved freely to (" << currentX << ", " << currentY << ")\n";
    }
};


void testRookMovement(Rook& rookPiece) {
    rookPiece.setPosition(5, 5);
}

int main() {
    Queen myQueen;
    testRookMovement(myQueen); 
    
    std::cout << "Bad design compiled, but logic is flawed.\n";
    return 0;
}