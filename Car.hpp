#pragma once

#include <stdexcept>
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"

class Car {
public:
    virtual ~Car(){};
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void reFill() = 0;
    virtual void changeEngine(PetrolEngine* engine);
    virtual void changeEngine(ElectricEngine* engine);

private:
    int speed_{0};
    bool speedIsValid(const int& speed);

    class InvalidSpeed : public std::range_error {
    public:
        InvalidSpeed(const std::string& msg)
            : std::range_error(msg) {}
    };

    class WrongEngine : public std::invalid_argument {
    public:
        WrongEngine(const std::string& msg)
            : std::invalid_argument(msg) {}
    };
};