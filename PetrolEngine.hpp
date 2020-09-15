#pragma once
class PetrolEngine {
    int power_;       // HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;

   public:
    PetrolEngine(int power, float capacity, int gears);
    ~PetrolEngine();
    void changeGear(int gear);
};
