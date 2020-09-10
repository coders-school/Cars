#include "InvalidGear.hpp"

InvalidGear::InvalidGear(const std::string& what_arg) : std::logic_error(what_arg) {}
