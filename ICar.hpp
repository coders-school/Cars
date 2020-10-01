#pragma once

#include "EngineParameters.hpp"

class ICar
{
public:

    virtual ~ICar(){};
    virtual void turnLeft() const = 0;
    virtual void turnRight() const = 0;
    virtual void brake() const = 0;
    virtual void accelerate(Speed speed) const = 0;
    virtual void start_engine() const = 0;
    virtual void stop_engine() const = 0;
    virtual void fill() const = 0;
    

};

