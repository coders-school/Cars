#include "InvalidGear.hpp"
#include <iostream>

InvalidGear::InvalidGear()
{
    std::cout << __FUNCTION__ << std::endl;
}

InvalidGear::~InvalidGear()
{
    std::cout << __FUNCTION__ << std::endl;
}

const char* InvalidGear::what() const throw()
{
    std::cout << "You can change gear from 5 to R !" << std::endl;
}
