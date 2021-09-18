#include "InvalidGear.hpp"
#include <stdexcept>

InvalidGear::InvalidGear(const std::string& message) : std::logic_error(message) {}
