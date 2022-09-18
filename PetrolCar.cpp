#include "PetrolCar.hpp"

#include "CarExceptions.hpp"

#include <iostream>

PetrolCar::PetrolCar(int maxSpeed, int maxReverseSpeed, const PetrolEngine& engine)
    : Car(maxSpeed, maxReverseSpeed)
    , engine_(engine)
{
    std::cout << "PetrolCar::" << __FUNCTION__ << " (copying engine)" << std::endl;
}

PetrolCar::PetrolCar(int maxSpeed, int maxReverseSpeed, PetrolEngine&& engine)
    : Car(maxSpeed, maxReverseSpeed)
    , engine_(engine)
{
    std::cout << "PetrolCar::" << __FUNCTION__ << " (moving engine)" << std::endl;
}

PetrolCar::~PetrolCar()
{
    std::cout << "PetrolCar::" << __FUNCTION__ << std::endl;
}

void PetrolCar::refill()
{
    std::cout << "PetrolCar::" << __FUNCTION__ << std::endl;
    if (currentSpeed_ != 0) {
        throw RefillError("Attempt to refuel car when the car is not stopped\n");
    }

    refuel();
}

void PetrolCar::refuel()
{
    std::cout << "PetrolCar::" << __FUNCTION__ << std::endl;
}

void PetrolCar::replaceEngine(PetrolEngine&& newEngine)
{
    std::cout << "PetrolCar::" << __FUNCTION__ << std::endl;
    if (currentSpeed_ != 0) {
        throw ReplaceEngineError("Attempt to change engine when the car is not stopped\n");
    }
    engine_ = std::move(newEngine);
    std::cout << "Engine replaced!" << std::endl;
}