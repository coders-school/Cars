#pragma once
#include <iostream>

class Engine {
public:
    Engine(int power, float capacity);
    virtual ~Engine();
    virtual void fillUp() = 0;
    virtual int getMaxSpeed() = 0;
    virtual int getMaxReverseSpeed() = 0;
    int getPower() { return power_; }
    float getCapacity() { return capacity_; }
    
protected:
    int power_;
    float capacity_;
};