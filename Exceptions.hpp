#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H

#include <stdexcept>
#include <string>

class InvalidGear : public std::runtime_error
{
public:
    InvalidGear(std::string a_Message) : std::runtime_error(a_Message) {}
    ~InvalidGear() {}
};

class IncorrectVelocity : public std::runtime_error
{
public:
    IncorrectVelocity(std::string a_Message) : std::runtime_error(a_Message) {}
    ~IncorrectVelocity(){};
};

class SpeedIsNotZero : public std::runtime_error
{
public:
    SpeedIsNotZero() : std::runtime_error("Unable to change engine. Car speed is not zero") {}
    ~SpeedIsNotZero(){};
};

#endif //!_EXCEPTIONS_H