#pragma once
#include "Engine.hpp"

#include <stdexcept>
#include <string>

class PetrolEngine : public Engine
{
public:
    struct InvalidGear : public std::logic_error {
        InvalidGear(std::string msg) : std::logic_error(msg)
        {
            
        }
    };
    PetrolEngine(int power, float capacity, int gears);
    ~PetrolEngine() override;
    void changeGear(int gear);
    void fillUp() override;
    int getMaxSpeed() override;
    int getMaxReverseSpeed() override;
private:
    int gears_;
    int currentGear_;
};
