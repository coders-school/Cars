#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class HybridCar
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    void charge();
    void refuel();
    void changeGear(int);

    PetrolEngine* petrolEngine_;
    ElectricEngine* electricEngine_;
};

