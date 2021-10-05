#pragma once
#include "Engine.hpp"
#include <iostream>


class PetrolEngine : public Engine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    // ~PetrolEngine();    
    void changeGear(int gear);

    // void start() override {std::cout << "Engine started.\n";}

private:
    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
