#pragma once
#include <stdexcept>

class InvalidGear : public std::logic_error
{
public:
    InvalidGear(std::string const & msg = "InvalidGear exception"): std::logic_error(msg)
    {}
};