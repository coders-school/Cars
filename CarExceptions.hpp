#pragma once

#include <stdexcept>
#include <string>

class InvalidGear : public std::logic_error::logic_error
{
  public:
    InvalidGear(const std::string& explanation)
        : std::logic_error::logic_error(explanation)
    { }
};

class RefillError : public std::logic_error::logic_error
{
  public:
    RefillError(const std::string& explanation)
        : std::logic_error::logic_error(explanation)
    { }
};

class ReplaceEngineError : public std::logic_error::logic_error
{
  public:
    ReplaceEngineError(const std::string& explanation)
        : std::logic_error::logic_error(explanation)
    { }
};