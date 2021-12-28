#include "PetrolEngine.hpp"

class PetrolCar
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    void refuel();
    void changeGear(int);

    PetrolEngine* petrolEngine_;
};

