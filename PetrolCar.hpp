#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    // void turnLeft();
    // void turnRight();
    // void brake();
    // void accelerate(int speed);
    void refuel();

    PetrolEngine* engine_;
};

