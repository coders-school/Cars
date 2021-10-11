#pragma once

#include <stdexcept>

class PetrolEngine {
public:
    PetrolEngine(int power, float capacity, int gears);
    ~PetrolEngine();
    void changeGear(int gear);
    int getCurrentGear() const {return currentGear_;};

    class InvalidGear : public std::logic_error {
    public:
        InvalidGear(const std::string& msg)
            : std::logic_error(msg) {}
    };

private:
    int power_;       //in HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
    bool gearIsValid(const int& gear);
    
};
