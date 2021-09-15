#pragma once
#include <stdexcept>
#include <vector>

class InvalidGear:std::logic_error
{
    public:
InvalidGear(const std::string & err):std::logic_error(err){};

};
class PetrolEngine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);
    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
