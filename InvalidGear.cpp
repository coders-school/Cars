#include "InvalidGear.hpp"
#include <iostream>

const char* InvalidGear::what() const throw()
{
    std::cout << "You can change gear from 5 to R !" << std::endl;
}
