#pragma once

#include "IEngine.hpp"

class PetrolEngine : public IEngine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    ~PetrolEngine();
    void changeGear(int gear);

    void start() const override;
    void stop() const override;

    int power_;         // in HP
    float capacity_;    // in ccm
    int gears_;
    int currentGear_;
};
