#include "PetrolEngine.hpp"
#include "Car.hpp"
class PetrolCar : public PetrolEngine, Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();
    void turnLeft() override;
    void turnRight() override;
    void brake() override;
    void accelerate(int speed) override;
    void refuel();

};

