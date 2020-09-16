#include "ElectricCar.hpp"
#include "PetrolCar.hpp"
#include "Car.hpp"
#include <memory>

class HybridCar : public ElectricCar, public PetrolCar
{
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();

    void restore() override;
};

