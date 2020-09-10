#include "InvalidGear.hpp"

#include <stdexcept>
#include <string>

InvalidGear::InvalidGear(const std::string& message)
    : std::logic_error(message) {}
