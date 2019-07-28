#pragma once
#include <cassert>
#include "Car.hpp"

void velocityTest(Car &testCar)
{
    unsigned maxspeed = testCar.getMaxSpeed();
    testCar.brake(maxspeed+1);
    assert(testCar.getVelocity() == 0);

    for(unsigned i=1; i<maxspeed; i++)
    {
        testCar.accelerate(1);
        assert(testCar.getVelocity() == i);    
    }    
        
    testCar.accelerate(testCar.getMaxSpeed());
    testCar.accelerate(10);
    assert(testCar.getVelocity() == testCar.getMaxSpeed());
    
    for(unsigned i=maxspeed-1; i>0; i--)
    {
        testCar.brake(1);
        assert(testCar.getVelocity() == i);    
    }
}