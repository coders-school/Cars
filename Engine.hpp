#pragma once

class Engine
{
public:
    Engine(int power);
    virtual ~Engine(){}
    virtual void dummyFunction(){}

private:
    int power_;           // in HP
};
