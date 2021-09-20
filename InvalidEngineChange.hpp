#pragma once

#include <stdexcept>
#include <string>

class InvalidEngineChange : public std::logic_error {
public:
    InvalidEngineChange(const std::string& message);
};
