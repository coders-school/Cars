#include "PetrolEngine.hpp"

#include <iostream>

PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : power_(power), capacity_(capacity), gears_(gears), currentGear_(0) {
    std::cout << __FUNCTION__ << std::endl;
}
/*
PetrolEngine::~PetrolEngine(){
 std::cout << __FUNCTION__ << std::endl; 
}
*/
bool PetrolEngine::validation(int value) {
    return value < 0;
}

void PetrolEngine::changeGear(int gear) {
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL
    //if(gear - )
    currentGear_ = gear;
    std::cout << __FUNCTION__ << std::endl;
}

int PetrolEngine::getPower() {
    return power_;
}

int PetrolEngine::getCapacity() {
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
    if (validation(capacity)) {
        std::cout << "capacity cannot be negative " << std::endl;
    } else {
        capacity_ = capacity;
    }
}

void PetrolEngine::setGears(int gears) {
    if (validation(gears)) {
        std::cout << "gears cannot be negative " << std::endl;
    } else {
        gears_ = gears;
    }
}

void PetrolEngine::setCurrentGear(int currentGear) {
    if (currentGear<-1) {
        std::cout << "gears cannot be negative " << std::endl;
    } else {
        currentGear_ = currentGear;
    }
}