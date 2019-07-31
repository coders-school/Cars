#pragma once

class Car
{
private:
	int velocity();
public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int velocityGrow);
    virtual void feed()=0;
};

