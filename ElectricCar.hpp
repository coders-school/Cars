#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : public ElectricEngine, Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void turnLeft() override;
    void turnRight() override;
    void brake() override;
    void accelerate(int speed) override;
    void charge();

};

