#pragma once

class Engine {
public:
    Engine(int power);
    virtual ~Engine();
    int power_;  // in HP
};