#pragma once
#include <stdexcept>

class InvalidGear : public std::logic_error {
public:
    InvalidGear(const char* info) noexcept : std::logic_error(info) {}
    ~InvalidGear() override = default;
};
