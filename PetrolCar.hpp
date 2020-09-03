#include "PetrolEngine.hpp"

class PetrolCar : public PetrolEngine
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    void refuel();

};

