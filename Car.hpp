#pragma once

#include "Engine.hpp"

#include <stdexcept>
#include <iostream>

class Car {
public:
    struct InvalidAccelerate : public std::logic_error {
        InvalidAccelerate(std::string msg) : std::logic_error(msg)
        {
            
        }
    };
    Car(Engine* engine);
    virtual ~Car();
    void accelerate(int speed);
    void fillUp();
    void turnLeft();
    void turnRight();
    void brake();

protected:
    Engine* engine_;
    int currentSpeed_ { };
    
};
