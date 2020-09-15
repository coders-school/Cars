#pragma once

#include <iostream>
#include <stdexcept>
class KMH {
   public:
    int value_;
    explicit KMH(int value) :
            value_(value) {
        if (value < 0) {
            throw std::invalid_argument("speed cannot be less than 0!\n");
        }
    }
};

enum class Direction {
    LEFT,
    UP,
    RIGHT,
    DOWN,
};

class Vehicle {
    KMH currentSpeed_{0};
    Direction currentDirection_{Direction::RIGHT};
    
    Direction getNewDirection(Direction turn);

   public:
    Vehicle() = default;
    virtual ~Vehicle() = default;
    void turnLeft();
    void turnRight();
    void changeSpeedTo(KMH);
    virtual void restore() = 0;
    Direction getCurrentDirection() const { return currentDirection_; }
    KMH getCurrentSpeed() const { return currentSpeed_; }
};
