#include "HybridCar.hpp"
#include <iostream>

HybridCar::HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
    : petrolEngine_(petrolEng)
    , electricEngine_(electricEng)
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::HybridCar(const HybridCar & car)
    : HybridCar( new PetrolEngine( car.petrolEngine_->getPower(), 
                                   car.petrolEngine_->getCapacity(), 
                                   car.petrolEngine_->getGears()), 
                 new ElectricEngine( car.electricEngine_->getPower(), 
                                     car.electricEngine_->getBatteryCapacity() ) ) 
{}

HybridCar::HybridCar( HybridCar && car )
: petrolEngine_( car.petrolEngine_ ), electricEngine_( car.electricEngine_ )
{   
    car.petrolEngine_ = nullptr;
    car.electricEngine_ = nullptr;
}

HybridCar & HybridCar::operator=(const HybridCar & car)
{
    if(&car != this)
    {
        delete petrolEngine_;
        delete electricEngine_;

        petrolEngine_ = new PetrolEngine( car.petrolEngine_->getPower(), 
                                          car.petrolEngine_->getCapacity(), 
                                          car.petrolEngine_->getGears());
        electricEngine_ = new ElectricEngine( car.electricEngine_->getPower(), 
                                              car.electricEngine_->getBatteryCapacity() );
    }
    return *this;
}

HybridCar & HybridCar::operator=(HybridCar && car)
{
    if(&car != this)
    {
        delete petrolEngine_;
        delete electricEngine_;
        
        petrolEngine_ = car.petrolEngine_;
        electricEngine_ = car.electricEngine_;

        car.petrolEngine_ = nullptr;
        car.electricEngine_ = nullptr;
    }

    return *this;
}

HybridCar::~HybridCar()
{ 
    delete petrolEngine_;
    delete electricEngine_;

    std::cout << __FUNCTION__ << std::endl; 
}

void HybridCar::charge()        { std::cout << __FUNCTION__ << std::endl; }
void HybridCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }
 

void HybridCar::setEngine(PetrolEngine* petrolEngine, ElectricEngine * electricEngine)
{
    delete petrolEngine_;
    delete electricEngine_;

    petrolEngine_ = petrolEngine;
    electricEngine_ = electricEngine;

    std::cout << __FUNCTION__ << std::endl; 
}

std::ostream & operator<<(std::ostream & out, HybridCar const & car)
{
    out << "Hybrid car ::\t" << *car.electricEngine_ << '\n' <<*car.petrolEngine_ << '\n';

    return out;
}