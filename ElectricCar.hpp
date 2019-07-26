#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine *engine);
    ElectricCar()= default;
    ~ElectricCar();

    void addEnergy();
	ElectricEngine* changeEngine(int, int);
protected:
    void charge();
private:
    ElectricEngine *electricEngine_;
};
