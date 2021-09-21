#include "InvalidGear.hpp"

InvalidGear::InvalidGear(const std::string& msg) : std::logic_error(msg) {};