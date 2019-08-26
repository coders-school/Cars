#pragma once

class Car
{
protected:
    int velocity = 0;
public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake(int speed);
    int getSpeed() const;
    void setSpeed(int speed);
    void accelerate(int speed);
    virtual void feed()=0;
};

