#include "Car.hpp"
#include <iostream>
#include <cassert> 

class ToLowSpeed {};
class ToHighSpeed {};

void Car::turnLeft()             { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()            { std::cout << __FUNCTION__ << std::endl; }
int Car::getSpeed()const       { std::cout<<"Car speed = "<<velocity<<std::endl; return velocity;}
void Car::setSpeed(int speed)   
{ 
    try
    {
      if (speed<-20 ) throw ToLowSpeed();
      if (speed>250) throw ToHighSpeed();
      else velocity=speed; 
      std::cout << "Car speed: " << velocity << "km/h." << std::endl;
    }
     catch(ToLowSpeed error)
    {
        std::cout << "Car speed can not be lower than -20." << std::endl; 
    }
    catch(ToHighSpeed error)
    {
       std::cout << "To high car speed value." << std::endl; 
    } 

    assert(speed>-20 && speed < 250);
    std::cout<<"SetSpeed assert test passed."<<std::endl; 
}
void Car::brake(int speed)
{
    if(speed>= this->getSpeed()) 
    {
        std::cout << "You want get higher speed than current spedd. Use ACCELERATE option" <<std::endl;
    }
    std::cout << __FUNCTION__ << " - ";
    setSpeed(speed);
}
void Car::accelerate(int speed)
{
    if(speed<= this->getSpeed()) 
    {
        std::cout << "You want get lower speed than current spedd. Use BRAKE option" <<std::endl;
    }

    std::cout << __FUNCTION__ << " - ";
    setSpeed(speed);
}
