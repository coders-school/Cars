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
    int SpeedLimitR = -30;

    std::cout << __FUNCTION__ << std::endl;
    if (velocity += speed < SpeedLimitR)
        velocity = SpeedLimitR;
    else if(velocity += speed > Vmax)
        velocity = Vmax;
    else 
        velocity += speed;

    assert(velocity >= SpeedLimitR && velocity <= Vmax);
    std::cout << "Execution continues past accelerate test\n";
    std::cout << "Current speed:" << velocity << std::endl;

}
void Car::brake(int breakTime)
{
    int SpdReducePerSec = 15;
    int SpeedLimitR = -30;

    std::cout << __FUNCTION__ << std::endl;

    if(breakTime > 0)
    {
        if(velocity - breakTime*SpdReducePerSec < 0)
            velocity = 0;
        else
            velocity = velocity - breakTime*SpdReducePerSec;
    }
    else 
    {
        breakTime = 0;
        std::cout<<"This is not a DeLorean, you can't time travel\n";
    }
    assert(breakTime >= 0);
    std::cout << "Execution continues past break time test\n";
    assert(velocity >= SpeedLimitR && velocity <= Vmax);
    std::cout << "Execution continues past break test\n";
 
     std::cout << "Current speed:" << velocity << std::endl;
}
 
