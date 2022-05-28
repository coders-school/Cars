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
void PetrolCar::changeGear(int gear) {
    if(!engine_->hasGear(gear)) {throw InvalidGear{"Engine does not have this gear!"};}
    if(engine_->isRunning() && gear == -1) {
        throw InvalidGear{"Cannot change to REAR from other gears than NEUTRAL!"};
    } else {engine_->setCurrentGear(gear);}
    std::cout << __FUNCTION__ << std::endl;
}
void PetrolCar::refill() {
    refuel();
}
