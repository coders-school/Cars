#pragma once

#include <stdint.h>

class Engine {
public:
    Engine(uint16_t power)
        : power_(power) {}
    virtual ~Engine() = default;
    uint16_t getPower() const { return power_; }

protected:
    uint16_t power_{};
};
