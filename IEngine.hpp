
#pragma once

class IEngine
{
public:

    virtual ~IEngine(){};
    virtual void start() const = 0;
    virtual void stop() const = 0;

};

