#include "Car.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    //void turnLeft();
    //void turnRight();
    //void brake();
    //void accelerate(int speed);
    void refuel();

    PetrolEngine* engine_;
};

