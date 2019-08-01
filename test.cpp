#include <cassert>
#include "Car.hpp"
#include "test.hpp"

void accelerateTest(Car &testCar)
{
    unsigned maxspeed = testCar.getMaxSpeed();
    testCar.brake(maxspeed+1);

    for(unsigned i=1; i<maxspeed; i++)
    {
        testCar.accelerate(1);
        assert(testCar.getVelocity() == i);    
    }    

    testCar.accelerate(testCar.getMaxSpeed());
    testCar.accelerate(10);
    assert(testCar.getVelocity() == testCar.getMaxSpeed());
}

void brakeTest(Car &testCar)
{
    unsigned maxspeed = testCar.getMaxSpeed();
    testCar.accelerate(maxspeed+1);

    for(unsigned i=maxspeed-1; i>0; i--)
    {
        testCar.brake(1);
        assert(testCar.getVelocity() == i);    
    }

    testCar.brake(10);
    assert(testCar.getVelocity() == 0);
}