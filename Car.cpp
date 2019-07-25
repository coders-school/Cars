#include "Car.hpp"
#include <iostream>

void Car::turnLeft()      { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake(int speed){ 
    std::cout << __FUNCTION__ << " - "; 
    carSpeed=speed;
    if (carSpeed == 0 )std::cout << "Car stopped" << std::endl;
    else std::cout << "Car slowed down to " << carSpeed << "km/h." << std::endl; 
}
int Car::accelerate(int speed) { 
    std::cout << __FUNCTION__ << " - ";
    carSpeed=speed;
    std::cout << "Car accelerated up to " << carSpeed << "km/h." << std::endl;
    return carSpeed; 
}
void Car::velocity(int carSpeed){
    std::cout << __FUNCTION__ << std::endl;
    accelerate(carSpeed); 
    brake(carSpeed);
}

