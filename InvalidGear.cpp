#include "InvalidGear.hpp"

#include <stdexcept>

InvalidGear::InvalidGear(const std::string& what)
    : std::range_error(what) {
}
