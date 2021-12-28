
#pragma once
#include <stdexcept>

struct InvalidGear : public std::logic_error {
    InvalidGear(std::string msg) : std::logic_error(msg) {}
};