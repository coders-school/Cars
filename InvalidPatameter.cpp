#include "InvalidParameter.hpp"

InvalidParameter::InvalidParameter(const std::string& msg) : std::logic_error(msg) {}