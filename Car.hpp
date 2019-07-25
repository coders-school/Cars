#pragma once
 
class Car
{
public:
    Car();
    virtual ~Car();

    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    void changeEngine(int, int);
    void getSpeed();
    virtual void gettypeCar();
    int setSpeed(int);
protected:
    int velocity; 
};
