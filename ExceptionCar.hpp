#pragma once
#include <iostream>
#include <exception>


class MyException : public std::exception
{
   public:
   const char * what () const noexcept;
};