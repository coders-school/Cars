#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() { 
    std::cout << __FUNCTION__ << std::endl;
    delete engine_;
}
void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }

void ElectricCar::restore() {
    charge();
}

void ElectricCar::changeEngine(int power, int batteryCapacity) {
    if(speed_ != 0) {
        return;
    }
    delete engine_;
    engine_ = new ElectricEngine(power, batteryCapacity);
    std::cout << "Engine change\n";
}
