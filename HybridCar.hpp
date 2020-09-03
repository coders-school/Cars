#include "ElectricCar.hpp"
#include "PetrolCar.hpp"
#include "Car.hpp"

class HybridCar : public ElectricCar, public PetrolCar
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();

    void restore() override;
};

