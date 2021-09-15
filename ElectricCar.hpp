#include "ElectricEngine.hpp"

class ElectricCar
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar() = default;
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    void charge();
private:
    ElectricEngine* engine_;
};

