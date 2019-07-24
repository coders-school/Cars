#pragma once
#include <exception>

class InvalidGear : public std::exception
{
public:
    InvalidGear();
    ~InvalidGear();
};
