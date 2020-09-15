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
    Direction currentDirection{Direction::RIGHT};

   public:
    Vehicle() = default;
    virtual ~Vehicle() = default;
    void turnLeft();
    void turnRight();
    void brakeTo(KMH);
    void accelerateTo(KMH);
    virtual void restore() = 0;
    Direction getCurrentDirection();
    KMH getCurrentSpeed();
};
