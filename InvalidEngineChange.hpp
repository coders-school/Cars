#pragma once

#include <stdexcept>

class InvalidEngineChange : public std::logic_error {
public:
    InvalidEngineChange(const std::string& errorMessage);
};