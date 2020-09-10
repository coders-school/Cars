#pragma once

class Engine {
public:
    Engine(int power);
    int getPower();
    ~Engine();

private:
    int power_;  // in HP
};
