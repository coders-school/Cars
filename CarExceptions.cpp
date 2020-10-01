#include "CarExceptions.hpp"

InvalidGear::InvalidGear(std::string p_msg) : logic_error(p_msg)
{
}

const char* InvalidGear::what() const throw()
{
    std::ostringstream o;
    o << logic_error::what();
    return o.str().c_str();
}
