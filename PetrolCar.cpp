#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(PetrolEngine* engine, Litre tankCapacity = Litre(60)) :
       engine_(engine),
       maxTankCapacity_(tankCapacity),
       currentTankCapacity_(tankCapacity) {
}

PetrolCar::~PetrolCar() {
    delete engine_;
}

void PetrolCar::refuel() {
    currentTankCapacity_ = maxTankCapacity_;
}

void PetrolCar::restore() {
    refuel();
}
