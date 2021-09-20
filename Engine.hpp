#pragma once

class Engine {
public:
    Engine(int power);
    virtual ~Engine() = default;

private:
    int power_;     // in HP
};
