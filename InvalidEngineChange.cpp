#include "InvalidEngineChange.hpp"

InvalidEngineChange::InvalidEngineChange(const std::string& errorMessage)
    : std::logic_error(errorMessage) {}