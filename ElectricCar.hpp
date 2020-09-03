#include "ElectricEngine.hpp"

class ElectricCar : public ElectricEngine
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    void charge();

};

