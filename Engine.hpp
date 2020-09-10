#pragma once

class Engine {
public:
    Engine(int power)
        : power_(power){};
    int getPower() { return power_; };
    virtual ~Engine() = default;

protected:
    int power_;  // in HP
};
