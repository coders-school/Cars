#include "Exceptions.hpp"

InvalidGear::InvalidGear(const std::string& what_arg) : std::logic_error(what_arg) {}

InvalidAcceleration::InvalidAcceleration(const std::string& what_arg) : std::logic_error(what_arg) {}

InvalidEngineChange::InvalidEngineChange(const std::string& what_arg) : std::logic_error(what_arg) {}

InvalidParameter::InvalidParameter(const std::string& what_arg) : std::logic_error(what_arg) {}
