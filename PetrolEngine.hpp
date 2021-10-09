#pragma once
#include <stdexcept>
#include <string>

class InvalidGear : public std::logic_error
{
public:
    InvalidGear(const std::string& what_str)
    : std::logic_error{ what_str }
    {}

    const char* what() const override;
};


class PetrolEngine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);

private:
    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
