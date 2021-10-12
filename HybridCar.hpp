#include "ElectricCar.hpp"
#include "PetrolCar.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();
    void reFill() override {
        PetrolCar::reFill();
        ElectricCar::reFill();
    };
    void changeEngine(std::unique_ptr<PetrolEngine> engine) override {
        PetrolCar::changeEngine(std::move(engine));
    };
    void changeEngine(std::unique_ptr<ElectricEngine> engine) override {
        ElectricCar::changeEngine(std::move(engine));
    };
};