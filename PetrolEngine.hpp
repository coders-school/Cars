#pragma once

#include <stdexcept>


class PetrolEngine
{
public:
    struct InvalidGear : public std::logic_error {
        InvalidGear(std::string msg): 
            std::logic_error(msg) 
        {}
    };

    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);

private:
    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
