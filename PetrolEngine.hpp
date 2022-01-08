#pragma once
#include <stdexcept>

class PetrolEngine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);
    int GetPower() {return power_;}
    float GetCapacity() {return capacity_;}
    int GetGear() {return gears_;}
    int GetCurrentGear() {return currentGear_;}
    
    class InvalidGear : public std::logic_error {
        public:
            InvalidGear(const std::string& msg)
            : std::logic_error(msg) {}
    };

private:
    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};

