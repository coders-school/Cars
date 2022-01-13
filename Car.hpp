#pragma once
#include "Engine.hpp"
class Car
{
public:
    Car();

    Car(const Car & ) = default;
    Car(Car && ) = default;

    Car & operator=(const Car &) = default;
    Car & operator=(Car &&) = default;

    virtual ~Car();
    
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    void refuel();

    //std::ostream & operator<<
    //virtual void setEngine(Engine * engine) = 0;

    //PetrolEngine* engine_;
};