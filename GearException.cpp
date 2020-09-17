#include "GearException.hpp"

const char* GearException::what() const noexcept {
    return msg_.c_str();
}