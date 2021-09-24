#pragma once

class PetrolEngine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    //~PetrolEngine();
    
    void changeGear(int gear);

    bool validation(int);
    int getPower();
    int getCapacity();
    int getGears();
    int getCurrentGear();
  
    void setPower(int);
    void setCapacity(float);
    void setGears(int);
    void setCurrentGear(int);

    private: 
    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
