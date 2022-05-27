#pragma once
#include <stdexcept>

class InvalidGear : public std::logic_error {
    InvalidGear(const std::string & msg) : std::logic_error(msg) {}
};
