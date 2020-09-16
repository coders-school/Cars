#include "InvalidSpeed.hpp"

InvalidSpeed::InvalidSpeed(const std::string& msg)
    : std::logic_error(msg) {}