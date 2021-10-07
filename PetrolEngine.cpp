#include "PetrolEngine.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include "InvalidGear.hpp"

PetrolEngine::PetrolEngine(int power, float capacity, int gears){
   try{
    if(TestConstructorData(power,capacity,gears))
    power_=power; 
    capacity_=capacity; 
    gears_=gears; 
    std::cout << __FUNCTION__ << std::endl;
   }catch(const std::invalid_argument& arg){
       std::cout<<arg.what()<<std::endl;
   }
}

bool PetrolEngine::TestConstructorData(int power, float capacity, int gears) {
    if (power < 0 || capacity < 0 || (gears < -1 || gears > 5)) {
        throw std::invalid_argument("Wrong parametr");
    }
    return true;
}

bool PetrolEngine::validation(int value) {
    return value <= 0;
}
bool PetrolEngine::correctnessOfTheGearChange(int gear) {
    if (abs(gear - getCurrentGear()) != 1) {
        throw InvalidGear{"wrong change Gear"};
    }
    return true;
}
void PetrolEngine::changeGear(int gear) {
    try {
        if (correctnessOfTheGearChange(gear)) {
            currentGear_ = gear;
        }
    } catch (const InvalidGear& inv) {
        std::cout << inv.what() << std::endl;
    }
}

int PetrolEngine::getPower() {
    return power_;
}

float PetrolEngine::getCapacity() {
    return capacity_;
}

int PetrolEngine::getGears() {
    return gears_;
}

int PetrolEngine::getCurrentGear() {
    return currentGear_;
}

void PetrolEngine::setPower(int power) {
    if (validation(power)) {
        std::cout << "power cannot be negative " << std::endl;
    } else {
        power_ = power;
    }
}

void PetrolEngine::setCapacity(float capacity) {
    if (capacity <= 0) {
        std::cout << "Capacity should be greater than zero  " << std::endl;
    } else {
        capacity_ = capacity;
    }
}

void PetrolEngine::setGears(int gears) {
    if (gears > 7) {
        std::cout << "The maximum number of gears is 7 " << std::endl;
    } else if (validation(gears)) {
        std::cout << "The number of gears should be greater than zero " << std::endl;
    } else {
        gears_ = gears;
    }
}

void PetrolEngine::setCurrentGear(int currentGear) {
    if (currentGear < -1 || currentGear > 5) {
        std::cout << "Gears should be in the range -1 to 5" << std::endl;
    } else {
        currentGear_ = currentGear;
    }
}