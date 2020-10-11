#include "Exception.hpp"

InvalidGear::InvalidGear(const std::string& msg)
    : std::runtime_error(msg) {}
