#include "Car.hpp"
#include <iostream>

void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::accelerate(int speed)
{ 
    std::cout << __FUNCTION__ << std::endl;
    if (velocity += speed < -30)
        Car::velocity = -30;
    else if(speed<Car::Vmax)
        Car::velocity += speed;
    else 
        Car::velocity = Car::Vmax;
    
    std::cout << "Current speed:" << Car::velocity << std::endl;

}
void Car::brake(int b)
{
    std::cout << __FUNCTION__ << std::endl;
    if(Car::velocity - b*15 <0)
        Car::velocity = 0;
    else
        Car::velocity = Car::velocity - b*15;
 
     std::cout << "Current speed:" << Car::velocity << std::endl;
}
 
