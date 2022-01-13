#pragma once
#include "Engine.hpp"
#include <iostream>

class Engine 
{
public:
    Engine(int power);

    Engine(const Engine &) = default;
    Engine(Engine &&) = default;

    Engine & operator=(const Engine &) = default;
    Engine & operator=(Engine &&) = default;

    virtual ~Engine();

    void setPower(int power){ power_ = power; }
    int getPower() const {return power_; }

private:
    int power_;             // in HP 
};