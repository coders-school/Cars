#pragma once

#include <stdexcept>

class PetrolEngine {
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);

private:
    int power_;       //in HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
    bool gearIsValid(const int& gear);

    class InvalidGear : public std::logic_error {
    public:
        InvalidGear(const std::string& msg)
            : std::logic_error(msg) {}
    };
};
