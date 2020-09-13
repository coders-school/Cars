#pragma once

class Engine {
public:
    explicit Engine(int power);
    ~Engine();

    int getPower() const;

private:
    int power_;  // in HP
};