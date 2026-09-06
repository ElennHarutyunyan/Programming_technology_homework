#include <iostream>
#include <vector>

class Piece {
public:
    virtual void move(int x, int y) = 0; 
    virtual ~Piece() = default;
};

class Rook : public Piece {
public:
    void move(int x, int y) override {
        std::cout << "Rook slides straight to (" << x << ", " << y << ")\n";
    }
};

class Queen : public Piece {
    void move(int x, int y) override {
        std::cout << "Queen moves in any direction to (" << x << ", " << y << ")\n";
    }
};


void executeMove(Piece& piece, int x, int y) {
    piece.move(x, y); 
}

int main() {
    Rook myRook;
    Queen myQueen;
    executeMove(myRook, 0, 5);
    executeMove(myQueen, 4, 4);

    std::cout << "Good design compiled and ran successfully.\n";
    return 0;
}