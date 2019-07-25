#include "Car.hpp"
#include <iostream>
#include <cassert>

void Car::turnLeft()
{
    if(velocity!=0)
        std::cout << __FUNCTION__ << std::endl;
    else
        std::cout << "You must move to turn!" << std::endl;
}
void Car::turnRight()
{
    if(velocity!=0)
        std::cout << __FUNCTION__ << std::endl;
    else
        std::cout << "You must move to turn!" << std::endl;
}
void Car::accelerate(int speed)
{ 
    std::cout << __FUNCTION__ << std::endl;
    if (Car::velocity += speed < -30)
        Car::velocity = -30;
    else if(speed<Car::Vmax)
        Car::velocity += speed;
    else 
        Car::velocity = Car::Vmax;

    assert(Car::velocity>=-30 && Car::velocity<=Car::Vmax);
    std::cout << "Execution continues past accelerate test\n";
    std::cout << "Current speed:" << Car::velocity << std::endl;

}
void Car::brake(int b)
{
    std::cout << __FUNCTION__ << std::endl;
    if(b>0)
    {
        if(Car::velocity - b*15 <0)
            Car::velocity = 0;
        else
            Car::velocity = Car::velocity - b*15;
    }
    else 
    {
        b=0;
        std::cout<<"This is not a DeLorean, you can't time travel\n";
    }
    assert(b >= 0);
    std::cout << "Execution continues past break time test\n";
    assert(Car::velocity>=-30 && Car::velocity<=Vmax);
    std::cout << "Execution continues past break test\n";
 
     std::cout << "Current speed:" << Car::velocity << std::endl;
}
 
