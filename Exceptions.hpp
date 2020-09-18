#pragma once

class InvalidGearException : public std::invalid_argument {
public:
    InvalidGearException(const std::string& information)
        : std::invalid_argument{"InvalidGearException: " + information} {}
};

class InvalidEngineChange : public std::runtime_error {
public:
    InvalidEngineChange(const std::string& information)
        : std::runtime_error("InvalidEngineChange: " + information) {}
};

class InvalidAccelerationException : public std::runtime_error {
public:
    InvalidAccelerationException(const std::string& information)
        : std::runtime_error("InvalidAccelerationException: " + information) {}
};
