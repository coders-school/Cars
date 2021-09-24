#pragma once
#include "Power.hpp"

class Engine {
public:
    Engine(Power power) : power_(power) {}
    virtual ~Engine() = default;

protected:
    Power power_;  // in HP
};
