#pragma once
#include <stdexcept>
#include <string>

class InvalidGear : public std::logic_error {
   public:
    InvalidGear(const std::string& msg) : std::logic_error(msg){};
};
