#pragma once

#include <string>
#include <exception>

class GearException : public std::exception{
public:
    GearException(const std::string msg) : msg_(msg) {};
    virtual const char* what() const noexcept override;
private:
    std::string msg_;
};