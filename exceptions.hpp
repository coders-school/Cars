#pragma once
#include <stdexcept>
#include <string>

class RearGearChangeException : public std::logic_error {
public:
    RearGearChangeException(
        const std::string& message =
            "Invalid gear attempt! There is no I cyk dwojeczka ever again!")
        : std::logic_error(message){};
};
class InvalidGearRangeException : public std::logic_error {
public:
    InvalidGearRangeException(
        const std::string& message =
            "This is not race car nor french tank! Invalid gear number")
        : std::logic_error(message) {}
};
