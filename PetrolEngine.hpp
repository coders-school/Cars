#pragma once

class InvalidGearException : public std::invalid_argument {
public:
    InvalidGearException(const std::string& information)
        : std::invalid_argument{"InvalidGearException: " + information} {}
};

class PetrolEngine {
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);

private:
    int power_;       // in HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
};
