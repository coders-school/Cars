#pragma once
#include <stdexcept>
#include <string>

class InvalidGear : public std::logic_error
{
public:
    InvalidGear(const std::string& what) : std::logic_error(what) {}
};

class PetrolEngine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);

    int getGear() const { return currentGear_; }
    int getPower() const { return power_; }
    int getCapacity() const { return capacity_; }

private:
    int power_;       // in HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
};
