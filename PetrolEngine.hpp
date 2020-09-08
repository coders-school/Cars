#pragma once

#include <stdexcept>

class InvalidGear : public std::logic_error {
public:
    InvalidGear(const std::string& eWhat);
};

class PetrolEngine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    ~PetrolEngine();
    void changeGear(int gear);
private:
    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
