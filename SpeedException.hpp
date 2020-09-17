#pragma once

#include <exception>
#include <string>

class SpeedException : std::exception{
public:
    SpeedException(std::string msg) : msg_(msg) {};
    virtual const char* what() const noexcept override;
private:
    std::string msg_;
};