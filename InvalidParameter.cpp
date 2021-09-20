#include "InvalidParameter.hpp"

InvalidParameter::InvalidParameter(const std::string& message)
    : std::logic_error(message) {}
