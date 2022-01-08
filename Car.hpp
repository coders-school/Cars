#pragma once
#include <stdexcept>

class Car
{
public:
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);

    std::string GetDirection() { return direction_;}
    int GetSpeed() {return speed_;}

    virtual void refill() = 0;
    virtual ~Car(){}

    class InvalidSpeed : public std::logic_error {
        public:
            InvalidSpeed(const std::string& msg)
            : std::logic_error(msg) {}
    };

private:
    int speed_ = 0;
    int maxSpeed_ = 260;
    std::string direction_ = "straight";
};
