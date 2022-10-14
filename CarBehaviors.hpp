#pragma once

#include "Engine.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class ChangeEngine {
protected:
    virtual void changeEngine(ElectricEngine* engine) = 0;

    virtual void changeEngine(PetrolEngine* engine) = 0;
};
