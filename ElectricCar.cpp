#include "ElectricCar.hpp"

#include "CarExceptions.hpp"

#include <iostream>

ElectricCar::ElectricCar(int maxSpeed, int maxReverseSpeed, const ElectricEngine& engine)
    : Car(maxSpeed, maxReverseSpeed)
    , engine_(engine)
{
    std::cout << "ElectricCar::" << __FUNCTION__ << " (copying engine)" << std::endl;
}

ElectricCar::ElectricCar(int maxSpeed, int maxReverseSpeed, ElectricEngine&& engine)
    : Car(maxSpeed, maxReverseSpeed)
    , engine_(engine)
{
    std::cout << "ElectricCar::" << __FUNCTION__ << " (moving engine)" << std::endl;
}

ElectricCar::~ElectricCar()
{
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::refill()
{
    std::cout << "ElectricCar::" << __FUNCTION__ << std::endl;
    if (currentSpeed_ != 0) {
        throw RefillError("Attempt to charge car when the car is not stopped\n");
    }
    charge();
}

void ElectricCar::charge()
{
    std::cout << "ElectricCar::" << __FUNCTION__ << std::endl;
}

void ElectricCar::replaceEngine(ElectricEngine&& newEngine)
{
    std::cout << "ElectricCar::" << __FUNCTION__ << std::endl;
    if (currentSpeed_ != 0) {
        throw ReplaceEngineError("Attempt to change engine when the car is not stopped\n");
    }
    engine_ = std::move(newEngine);
    std::cout << "Engine replaced!" << std::endl;
}
