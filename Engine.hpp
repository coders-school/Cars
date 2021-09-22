#pragma once
#include <iostream>

class Engine {
public:
    Engine(int power, float capacity);
    virtual ~Engine();
    virtual void fillUp() = 0;
    int getPower() { return power_; }
    
protected:
    int power_;
    float capacity_;
};