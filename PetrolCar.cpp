#include "PetrolCar.hpp"

PetrolCar::PetrolCar(std::shared_ptr<PetrolEngine> engine)
    : engine_(engine)
{std::cout << __FUNCTION__ << std::endl;}

PetrolCar::~PetrolCar() {std::cout << __FUNCTION__ << std::endl;}
void PetrolCar::refuel() {std::cout << __FUNCTION__ << std::endl;}
void PetrolCar::changeEngine(std::shared_ptr<PetrolEngine> pe) {
    if(!engine_->isRunning() ) {
        engine_ = pe;
    } else {
        throw CarLogicError{"Cannot change engine while running!"};
    }
    
}
void PetrolCar::refill() {
    refuel();
}
