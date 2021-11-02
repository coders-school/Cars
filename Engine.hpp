#pragma once
#include "Engine.hpp"

class Engine 
{
public:
    Engine(int power);
    virtual ~Engine();

private:
    int power_;             // in HP 
};