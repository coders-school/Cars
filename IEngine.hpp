
#pragma once

class IEngine
{
public:

    virtual ~IEngine(){};
    virtual void start() const = 0;
    virtual void stop() const = 0;
//    virtual void open_throttle() const = 0;
//    virtual void close_throttle() const = 0;

};

