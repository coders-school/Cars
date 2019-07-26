#pragma once
#include <functional>

class InvalidGear : public std::bad_function_call
{
public:
    const char* what() const noexcept;
};
