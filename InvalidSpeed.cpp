#include "InvalidSpeed.hpp"

InvalidSpeed::InvalidSpeed(const std::string& errorMessage)
    : std::logic_error(errorMessage) {}

