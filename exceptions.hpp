#include "exception"

class RearGearChangeException : public std::exception {
  const char* what () const throw (){
    return "Invalid gear attempt! There is no I cyk dwojeczka ever again!";
  }
};

class InvalidGearRangeException : public std::exception {
  const char* what () const throw (){
    return "This is not race car nor french tank! Invalid gear number";
  }
};
