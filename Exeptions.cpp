#include "Exeptions.hpp"2

InvalidGear::InvalidGear(const std::string& msg) : std::logic_error(msg) {};

InvalidParameter::InvalidParameter(const std::string& msg) : std::logic_error(msg) {}