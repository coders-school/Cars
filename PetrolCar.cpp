#include "PetrolCar.hpp"
#include <iostream>
 
PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::PetrolCar(const PetrolCar & car)
 : PetrolCar(new PetrolEngine(car.engine_->getPower(), 
                              car.engine_->getCapacity(), 
                              car.engine_->getGears()))
{}

PetrolCar::PetrolCar(PetrolCar && car): engine_(car.engine_)
{   
    car.engine_ = nullptr;
}

PetrolCar & PetrolCar::operator=(const PetrolCar & car)
{
    if(&car != this)
    {
        delete engine_;
        
        engine_ = new PetrolEngine( car.engine_->getPower(), 
                                    car.engine_->getCapacity(), 
                                    car.engine_->getGears() );
    }
    return *this;
}

PetrolCar & PetrolCar::operator=(PetrolCar && car)
{
    if(&car != this)
    {
        delete engine_;
        
        engine_ = car.engine_;
        car.engine_ = nullptr;
    }

    return *this;
}

PetrolCar::~PetrolCar()         
{ 
    std::cout << __FUNCTION__ << std::endl; 
    delete engine_;
}

void PetrolCar::setEngine(PetrolEngine * engine) 
{
    if(engine_ != engine)
    {
        delete engine_;
        engine_ = engine;
    }
    
    { std::cout << __FUNCTION__ << std::endl; }
}

std::ostream & operator<<(std::ostream & out, PetrolCar const & car)
{
    out << "Petrol car\t" << *car.engine_ << '\n';

    return out;
}
