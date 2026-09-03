#include <iostream>
#include <vector>
#include <memory>

enum AnimalType { cat, dog, cow };

class Animal {
public:
    explicit Animal( AnimalType t ) : type{ t } {}
    AnimalType getType() const noexcept { return type; }
    virtual ~Animal() = default; 
private:
    AnimalType type;
};

class Cat : public Animal {
public:
    Cat() : Animal{ cat } {}
};

class Dog : public Animal {
public:
    Dog() : Animal{ dog } {}
};

class Cow : public Animal {
public:
    Cow() : Animal{ cow } {}
};

void makeAnimalSound( Animal const& animal ) {
    switch ( animal.getType() ) {
        case cat:
            std::cout << "Meow!\n";
            break;
        case dog:
            std::cout << "Woof!\n";
            break;
        case cow:
            std::cout << "Moo!\n";
            break;
    }
}

void feedAnimal( Animal const& animal ) {
    switch ( animal.getType() ) {
        case cat:
            std::cout << "Eating fish...\n";
            break;
        case dog:
            std::cout << "Eating bones...\n";
            break;
        case cow:
            std::cout << "Eating grass...\n";
            break;
    }
}

int main(){
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back( std::make_unique<Cat>() );
    animals.push_back( std::make_unique<Dog>() );
    animals.push_back( std::make_unique<Cow>() );

    for ( auto const& a : animals ) {
        makeAnimalSound( *a );
        feedAnimal( *a );
    }

    return 0;
}