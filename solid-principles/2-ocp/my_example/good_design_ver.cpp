#include <iostream>
#include <vector>
#include <memory>


class Animal {
public:
    virtual ~Animal() = default;
    virtual void makeSound() const = 0; 
    virtual void eat() const = 0;       
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow!\n";
    }
    void eat() const override {
        std::cout << "Eating fish...\n";
    }
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof!\n";
    }
    void eat() const override {
        std::cout << "Eating bones...\n";
    }
};

class Cow : public Animal {
public:
    void makeSound() const override {
        std::cout << "Moo!\n";
    }
    void eat() const override {
        std::cout << "Eating grass...\n";
    }
};

void processAnimals( std::vector<std::unique_ptr<Animal>> const& animals ) {
    for ( auto const& a : animals ) {
        a->makeSound(); 
        a->eat();      
    }
}

int main() {
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back( std::make_unique<Cat>() );
    animals.push_back( std::make_unique<Dog>() );
    animals.push_back( std::make_unique<Cow>() );

    processAnimals( animals );
    return 0;
}