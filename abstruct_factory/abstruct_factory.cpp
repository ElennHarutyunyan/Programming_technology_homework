#include <iostream>
#include <memory>
#include <string>


class Chair {
public:
    virtual ~Chair() = default;
    virtual std::string hasLegs() const = 0;
};

class Sofa {
public:
    virtual ~Sofa() = default;
    virtual std::string styleDescription() const = 0;
};


class VictorianChair : public Chair {
public:
    std::string hasLegs() const override {
        return "Victorian Chair with carved wooden legs.";
    }
};

class VictorianSofa : public Sofa {
public:
    std::string styleDescription() const override {
        return "Victorian Sofa with ornate upholstery.";
    }
};


class ModernChair : public Chair {
public:
    std::string hasLegs() const override {
        return "Modern Chair with sleek metal legs.";
    }
};

class ModernSofa : public Sofa {
public:
    std::string styleDescription() const override {
        return "Modern Sofa with minimalist low profile.";
    }
};


class FurnitureFactory {
public:
    virtual ~FurnitureFactory() = default;
    virtual std::unique_ptr<Chair> createChair() const = 0;
    virtual std::unique_ptr<Sofa> createSofa() const = 0;
};


class VictorianFurnitureFactory : public FurnitureFactory {
public:
    std::unique_ptr<Chair> createChair() const override {
        return std::make_unique<VictorianChair>();
    }
    std::unique_ptr<Sofa> createSofa() const override {
        return std::make_unique<VictorianSofa>();
    }
};

class ModernFurnitureFactory : public FurnitureFactory {
public:
    std::unique_ptr<Chair> createChair() const override {
        return std::make_unique<ModernChair>();
    }
    std::unique_ptr<Sofa> createSofa() const override {
        return std::make_unique<ModernSofa>();
    }
};


void renderFurniture(const FurnitureFactory& factory) {
    auto chair = factory.createChair();
    auto sofa = factory.createSofa();

    std::cout << chair->hasLegs() << "\n";
    std::cout << sofa->styleDescription() << "\n";
}


int main() {
    std::cout << "--- Ordering Victorian Furniture ---\n";
    auto victorianFactory = std::make_unique<VictorianFurnitureFactory>();
    renderFurniture(*victorianFactory);

    std::cout << "\n--- Ordering Modern Furniture ---\n";
    auto modernFactory = std::make_unique<ModernFurnitureFactory>();
    renderFurniture(*modernFactory);

    return 0;
}