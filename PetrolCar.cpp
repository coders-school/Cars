#include "PetrolCar.hpp"

PetrolCar::PetrolCar(std::shared_ptr<PetrolEngine> engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()         { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::changeEngine(std::shared_ptr<PetrolEngine> pe) {
    engine_ = pe;
}
void PetrolCar::refill() {
    refuel();
}
