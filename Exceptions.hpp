#include <stdexcept>

class InvalidGear : public std::logic_error {
public:
    InvalidGear(std::string msg) : std::logic_error(msg) {}    
};

class InvalidSpeed : public std::range_error {
public:
    InvalidSpeed(std::string msg) : std::range_error(msg) {}
};