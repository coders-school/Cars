#include "Car.hpp"
#include <iostream>

void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake(int speed){ 
    std::cout << __FUNCTION__ << " - "; 
    if (velocity<speed) {
        std::cout << "Carent speed is lower than desired speed." << std::endl;
        std::cout << "\t Use accelerate function." << std::endl;
    }
    else{
    velocity=speed;
    if (velocity == 0 )std::cout << "Car stopped" << std::endl;
    else std::cout << "Car slowed down to " << velocity << "km/h." << std::endl; 
    }
}
void Car::accelerate(int speed) { 
    std::cout << __FUNCTION__ << " - ";
    try{
      if (speed<0 ) throw 0;
      if (speed>250) throw 1;
      velocity=speed; 
      std::cout << "Car accelerated up to " << velocity << "km/h." << std::endl;
    }
    catch(int x){
        if (x==0) std::cout << "Car speed can not be lower than 0." << std::endl; 
        if (x==1) std::cout << "To high car speed value." << std::endl; 
    }

    
}

void Car::getSpeed()    {std::cout<<"Car speed = "<<velocity<<std::endl;}

void Car::setSpeed(int speed)    {velocity=speed;}

