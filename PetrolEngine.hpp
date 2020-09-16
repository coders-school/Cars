#pragma once

enum class GearBox {
    rear = -1,
    neutral = 0,
    first = 1,
    second = 2,
    third = 3,
    fourth = 4,
    fifth = 5,
    sixth = 6
};

class PetrolEngine {
public:
    PetrolEngine(int power, float capacity, int gears);
    void setGear(GearBox gear);

private:
    int power_;
    float capacity_;  // in ccm
    int gears_;
    GearBox currentGear_;
};
