#include "InvalidEngineChange.hpp"

InvalidEngineChange::InvalidEngineChange(const std::string& message)
    : std::logic_error(message) {}
