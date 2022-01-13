#pragma once
#include "Engine.hpp"
#include <iostream>

class PetrolEngine : public Engine
{
public:
    PetrolEngine(int power, float capacity, int gears);

    PetrolEngine(const PetrolEngine &) = default;
    PetrolEngine(PetrolEngine &&) = default;

    PetrolEngine & operator=(const PetrolEngine &) = default;
    PetrolEngine & operator=(PetrolEngine &&) = default;

    ~PetrolEngine() override;
    
    void changeGear(int gear);

    void setCapacity(float capacity){ capacity_ = capacity; }
    void setGears(int gears){gears_ = gears; }
    void setCurrentGear(int gear) { currentGear_ = gear; }

    float getCapacity() const { return capacity_; }
    int getGears() const { return gears_; }
    int getCurrentGear() const { return currentGear_; }

    friend std::ostream & operator<<(std::ostream & out, PetrolEngine const & engine);

private:
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
