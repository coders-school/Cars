#include "ElectricCar.hpp"
#include "PetrolCar.hpp"

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();
    void reFill() override {
        PetrolCar::reFill();
        ElectricCar::reFill();
    };
};
