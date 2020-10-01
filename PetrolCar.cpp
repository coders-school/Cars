#include "PetrolCar.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine))
{
    std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl;
}

PetrolCar::~PetrolCar()          { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void PetrolCar::turnLeft() const      { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void PetrolCar::turnRight() const    { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void PetrolCar::brake()     const   { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void PetrolCar::accelerate(Speed speed) const { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }
void PetrolCar::fill() const       { std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl; }

void PetrolCar::start_engine() const {
  std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl;
    engine_->start();
}
void PetrolCar::stop_engine() const {
  std::cout << __FUNCTION__ << ": " <<  __FILE__  << ": " <<  __LINE__  << std::endl;
    engine_->stop();
}

