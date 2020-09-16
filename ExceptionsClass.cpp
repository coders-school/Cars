#include "ExceptionsClass.hpp"

InvalidChangeEngine::InvalidChangeEngine(const std::string& msg)
    : std::logic_error(msg) {}

InvalidGear::InvalidGear(const std::string& msg)
    : std::logic_error(msg) {}

InvalidSpeed::InvalidSpeed(const std::string& msg)
    : std::logic_error(msg) {}

InvalidCharge::InvalidCharge(const std::string& msg)
    : std::logic_error(msg) {}