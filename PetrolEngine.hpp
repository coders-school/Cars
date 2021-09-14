#pragma once

#include <stdexcept>
#include <string>

class InvalidGear : public std::logic_error {
   public:
    InvalidGear(const std::string& msg) : std::logic_error(msg) {
    }
};
class PetrolEngine {
   public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);
    int getCurrentGear() const;

    int power_;       // in HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
};
