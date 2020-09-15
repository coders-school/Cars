#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine) :
        engine_(engine),
        currentBatteryLevel_(engine_->getBatterCapacity()) {
}

ElectricCar::~ElectricCar() {
    delete engine_;
}
void ElectricCar::charge() {
    currentBatteryLevel_ = engine_->getBatterCapacity();
}

void ElectricCar::restore() {
    charge();
}
