#pragma once

class Engine {
private:
    int power_{};

public:
    Engine(int power);
    int getPower() const { return power_; }
    ~Engine() {};
};
