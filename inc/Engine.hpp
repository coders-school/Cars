#pragma once

class Engine {
public:
    Engine(int power)
        : power_(power){};
    virtual ~Engine() = default;

    int getPower() { return power_; };

protected:
    int power_;  // in HP
};
