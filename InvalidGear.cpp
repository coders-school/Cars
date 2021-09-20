#include "InvalidGear.hpp"

InvalidGear::InvalidGear(const std::string& message)
    : std::logic_error(message) {}
