#pragma once
#include <iostream>
#include <memory>

class Car {
public:
    Car();
    virtual ~Car();

    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;
    virtual void brake() = 0;
    virtual void accelerate(int);



    
};
