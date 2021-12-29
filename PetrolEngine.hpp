#pragma once

class PetrolEngine {
public:
    PetrolEngine(int, float, int);
    void changeGear(int);

private:
    int power_;       // in HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
};
