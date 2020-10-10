#pragma once

class PetrolEngine {
private:
    int power_;
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;

public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);

};
