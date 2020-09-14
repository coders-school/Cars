#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine))
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar() {
  std::cout << __FUNCTION__ << std::endl;
}

void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::restore(){
    refuel();
}
PetrolEngine *PetrolCar::getPetrolEngineData() const {
  return engine_.get();
}

std::unique_ptr<PetrolEngine> PetrolCar::pullOutPetrolEngine() {
  return std::move(engine_);
}

void PetrolCar::accelerate(int a){
    if(engine_){
        if(a > 0)
        std::cout << "\nAccelerate to: " << a << "km\\h\n";
        else throw std::invalid_argument("\nInvalid speed, can't be negative\n");
    } else std::cout << "\nThis car doesn't have an engine!\n";
}