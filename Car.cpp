#include "Car.hpp"
#include <iostream>

void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake(int speed)      { velocity-=speed; std::cout <<"Slowing down to: "<<velocity<<std::endl;}
void Car::accelerate(int speed)
{
    if (speed<0)
            std::cout<<"Can't accelerate to negative speed value."<<std::endl;
    else if (speed>200)
            std::cout<<"Can't accelerate to 200+." <<std::endl;
    else{
            velocity+=speed;
            std::cout <<"Accelerate to: " <<velocity<<std::endl;}
 }
void Car::set_speed(int speed)  { velocity=speed;  std::cout << __FUNCTION__ << std::endl; }
int Car::get_speed()const       { std::cout<<"Speed = "<<velocity<<std::endl; return velocity; }
