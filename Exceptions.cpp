#include "Exceptions.hpp"

InvalidGear::InvalidGear(const std::string& arg)
    : std::logic_error(arg) {}

InvalidRestore::InvalidRestore(const std::string& arg)
    : std::logic_error(arg) {}

InvalidSpeed::InvalidSpeed(const std::string& arg)
    : std::logic_error(arg) {}
