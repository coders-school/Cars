#pragma once

#include <stdexcept>
#include <string>

class InvalidGear : public std::range_error {
public:
    InvalidGear(const std::string& what);
};
