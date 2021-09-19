#include "InvalidSpeed.hpp"

InvalidSpeed::InvalidSpeed(const std::string& message) : std::logic_error(message) {}
