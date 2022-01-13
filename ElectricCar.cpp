#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::ElectricCar(const ElectricCar & car)
 : ElectricCar(new ElectricEngine(car.engine_->getPower(), 
                                  car.engine_->getBatteryCapacity() ) )
{}

ElectricCar::ElectricCar(ElectricCar && car): engine_(car.engine_)
{   
    car.engine_ = nullptr;
}

ElectricCar & ElectricCar::operator=(const ElectricCar & car)
{
    if(&car != this)
    {
        delete engine_;
        
        engine_ = new ElectricEngine(car.engine_->getPower(), 
                                     car.engine_->getBatteryCapacity() );
    }
    return *this;
}

ElectricCar & ElectricCar::operator=(ElectricCar && car)
{
    if(&car != this)
    {
        delete engine_;
        
        engine_ = car.engine_;
        car.engine_ = nullptr;
    }

    return *this;
}

ElectricCar::~ElectricCar()
{ 
    std::cout << __FUNCTION__ << std::endl; 
    delete engine_;
}

void ElectricCar::charge()        { std::cout << __FUNCTION__ << std::endl; }

void ElectricCar::setEngine(ElectricEngine * engine)
{
    if(engine_ != engine)
    {
        delete engine_;
        engine_ = engine;
    }
    { std::cout << __FUNCTION__ << std::endl; }
}

std::ostream & operator<<(std::ostream & out, ElectricCar const & car)
{
    out << "Electric car\t" << *car.engine_ << '\n';

    return out;
}