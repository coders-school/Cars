#include <stdexcept>
#include <string>

class InvalidGear : public std::logic_error {
public:
    InvalidGear(std::string msg)
        : std::logic_error(msg) {}
};

class InvalidEngine : public std::invalid_argument {
public:
    InvalidEngine(std::string msg)
        : std::invalid_argument(msg) {}
};