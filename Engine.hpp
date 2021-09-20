#pragma once

class Engine {
public:
    Engine(int power) : power_(power) {}
    virtual ~Engine() = default;

protected:
    int power_;  // in HP
};
