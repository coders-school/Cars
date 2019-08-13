#include "ExceptionCar.hpp"

const char * MyException::what() const noexcept
{
    return "Invalid Value!";
}
