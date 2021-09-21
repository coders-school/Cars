#pragma once 

#include <stdexcept>
#include <string>

class InvalidSpeed : public std::logic_error {
    InvalidSpeed(const std::string& msg);
};