#pragma once

class Refuelable {
public:
    virtual ~Refuelable() = default;
    virtual void refuel() = 0;
};
