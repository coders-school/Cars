#pragma once
#include <stdexcept>
#include <string>

class InvalidGear : public std::logic_error{
public: 
    InvalidGear(std::string str);
};