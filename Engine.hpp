#pragma once

class Engine {
public:
    Engine(int power);
    virtual ~Engine();
    
protected:
    int power_;  // in HP
};