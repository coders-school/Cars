#include "InvalidGear.hpp"

InvalidGear::InvalidGear(const std::string& errorMessage)
    : std::logic_error(errorMessage) {}
