#pragma once

class Engine {
public:
    explicit Engine(int power);
    virtual ~Engine();

    int getPower() const;

private:
    int power_;  // in HP
};
