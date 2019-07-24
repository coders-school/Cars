#include "Car.hpp"
#include"Exceptions.hpp"
#include <iostream>

Car::Car()		  { std::cout << __FUNCTION__ << std::endl;
                            velocity=0; }
Car::~Car()		  { std::cout << __FUNCTION__ << std::endl; }

void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake()
{
                            std::cout << __FUNCTION__ << std::endl;

}
void Car::accelerate(int value)
{
                            std::cout << __FUNCTION__ << std::endl;
                            setSpeed(value);
}
void Car::changeEngine(int, int){}
void Car::getSpeed()      { std::cout<<"Speed: "<<velocity<<std::endl; }
int Car::setSpeed(int value)
{
    try
    {
        if(value>=300)  throw ExcepptionMaxSpeed();
        if(value<=-20)  throw ExcepptionRSpeed();
         velocity=value;
         getSpeed();
   }
    catch (ExcepptionMaxSpeed Ex)
    {
        Ex.getException();
    }
    catch (ExcepptionRSpeed Ex)
    {
        Ex.getException();
    }
}
