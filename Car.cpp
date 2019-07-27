#include "Car.hpp"
#include <iostream>

class ToLowSpeed {};
class ToHighSpeed {};

void Car::turnLeft()             { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()            { std::cout << __FUNCTION__ << std::endl; }
void Car::getSpeed()const       { std::cout<<"Car speed = "<<velocity<<std::endl; }
void Car::setSpeed(int speed)    { 
    try
    {
      if (speed<-20 ) throw ToLowSpeed();
      if (speed>250) throw ToHighSpeed();
      velocity=speed; 
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
}
void Car::brake(int speed)
{
    std::cout << __FUNCTION__ << " - "<<std::endl;
    setSpeed(speed);
}
void Car::accelerate(int speed)
{
    std::cout << __FUNCTION__ << " - "<<std::endl;
    setSpeed(speed);
}
