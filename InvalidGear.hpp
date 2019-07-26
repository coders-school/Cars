#pragma once
#include <exception>

class InvalidGear : public std::exception

{
public:
     virtual const char *what() const throw()
     {
          return "Exception! Invalid value!";
     }
};