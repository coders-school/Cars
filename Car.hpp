#pragma once
#include <iostream>

class Car
{
public:
    virtual ~Car() {}
    
    virtual void turnLeft()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    virtual void turnRight()
    {
        std::cout << __FUNCTION__ << std::endl;
    }

    virtual void brake() = 0;
    virtual void accelerate(int speed) = 0;
    virtual void topUp() = 0;
};

