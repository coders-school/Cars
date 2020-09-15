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

class Vehicle {
   public:
    Vehicle();
    virtual ~Vehicle();
    void turnLeft(){};
    void turnRight(){};
    void brakeTo(KMH){};
    void accelerateTo(KMH){};
    virtual void restore() = 0;
};
