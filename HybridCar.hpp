#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "Car.hpp"

class HybridCar : public PetrolEngine, ElectricEngine, Car
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();
    void turnLeft() override;
    void turnRight() override;
    void brake() override;
    void accelerate(int speed) override;
    void charge();
    void refuel();

    PetrolEngine* petrolEngine_;
    ElectricEngine* electricEngine_;
};

