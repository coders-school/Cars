#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class HybridCar
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar() = default;
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    void charge();
    void refuel();

private:
    PetrolEngine* petrolEngine_;
    ElectricEngine* electricEngine_;
};

