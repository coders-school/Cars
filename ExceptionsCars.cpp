#include "ExceptionsCars.hpp"

InvalidGear::InvalidGear(const std::string& err)
    : std::logic_error(err) {}

InvalidAccelerate::InvalidAccelerate(const std::string& err)
    : std::logic_error(err) {}