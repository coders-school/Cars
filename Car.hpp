#pragma once

class Car
{

public:
    int Vmax;
    int velocity = 0;
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake(int breakTime);
    void accelerate(int speed);
    virtual void feed()=0;
    
};

