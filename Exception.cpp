#include "Exception.hpp"

InvalidGear::InvalidGear(const std::string& msg)
    : std::runtime_error(msg) {}

InvalidEngineChange::InvalidEngineChange(const std::string& msg)
    : std::runtime_error(msg) {}

InvalidAcceleration::InvalidAcceleration(const std::string& msg)
    : std::runtime_error(msg) {}
