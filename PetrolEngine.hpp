#pragma once
//#include "Engine.hpp"

class PetrolEngine {
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);

    int getGear() const;
    int getCurrentGear() const;
    float getCapacity() const;
    int getPower() const;
    //int power_;  // in HP
                 // float capacity_;  // in ccm
private:
    int power_;  // in HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
    
};
