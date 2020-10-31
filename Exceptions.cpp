#include "Exceptions.hpp"

InvalidGear::InvalidGear(const std::string & arg) 
    : std::logic_error(arg) {}
    