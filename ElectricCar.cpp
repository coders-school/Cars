#include "ElectricCar.hpp"
#include <iostream>

// ElectricCar::ElectricCar(ElectricEngine* engine)
ElectricCar::ElectricCar(Engine* engine)
    : engine_(engine)
    // : Car(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar()       { std::cout << __FUNCTION__ << std::endl; }
// void ElectricCar::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
// void ElectricCar::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
// void ElectricCar::brake()         { std::cout << __FUNCTION__ << std::endl; }
// void ElectricCar::accelerate(int) { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }

void ElectricCar::refill() {
    charge();
}