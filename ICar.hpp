#pragma once

class ICar
{
public:

    virtual ~ICar(){};
    virtual void turnLeft() const = 0;
    virtual void turnRight() const = 0;
    virtual void brake() const = 0;
    virtual void accelerate(unsigned int speed) const = 0;

};

