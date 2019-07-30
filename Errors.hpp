#pragma once

#include <exception>

struct InvalidGear : public std::exception
{
    const char * what () const throw ()
    {
        return "Invalid Gear Sequence";
    }
};
