#include "InvalidGear.hpp"
#include <iostream>

const char* InvalidGear::what() const noexcept
{
    std::cout << "You can change gear to R (reverse) only when current gear is equal 0 (Neutral) !" << std::endl;
}
