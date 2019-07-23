#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar()       {
    delete(engine_);
    engine_ = nullptr;
    std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::feed()          { charge(); }

void ElectricCar::changeEngine(Engine* newEngine) {
    if (velocity != 0)
        throw std::logic_error( "Car is moving now! Engine exchange impossible ");
    engine_ = dynamic_cast<ElectricEngine*>(newEngine);

}