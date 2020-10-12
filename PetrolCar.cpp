#include "PetrolCar.hpp"
#include <iostream>
#include "MovingCar.hpp"
#include "InvalidEngine.hpp"

PetrolCar::PetrolCar(std::shared_ptr<PetrolEngine> engine)
    : engine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
    //delete engine_;
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::refuel() {
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::restore() {
    refuel();
}

void PetrolCar::changeGear(int gear) {
    engine_->changeGear(gear);
}

int PetrolCar::getGear() const {
    return engine_->getGear();
}

//void PetrolCar::changeEngine(Engine* engine){
void PetrolCar::changeEngine(std::shared_ptr<PetrolEngine> engine){
    std::cout << __FUNCTION__ << std::endl;
    if (getSpeed() != 0) {
        throw MovingCar("Car is in move");
    } else {
        engine_ = engine;
    }
}
