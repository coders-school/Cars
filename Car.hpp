#pragma once
#include <exception>
#include <memory>
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

constexpr float maxSpeed = 300.0;

class Car
{
public:
    virtual ~Car(){}
    
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void refill() = 0;
    virtual void changeEngine(std::unique_ptr<PetrolEngine> enginePtr);
    virtual void changeEngine(std::unique_ptr<ElectricEngine> enginePtr);
    
    // getters
    float getSpeed() const { return speed_; }
    
    // execption
    class CarMoving : public std::logic_error {
        public:
            CarMoving(const std::string &msg) :
                std::logic_error(msg) {}
    };
private:
    float speed_;
};
