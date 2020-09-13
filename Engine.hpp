#pragma once

class Engine {
public:
    explicit Engine(int power);
    virtual ~Engine();

    int getPower() const;

protected:
    int power_;
};