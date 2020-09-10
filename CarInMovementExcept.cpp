#include "CarInMovementExcept.hpp"

#include <stdexcept>

CarInMovementExcept::CarInMovementExcept(const std::string& what)
    : std::logic_error(what) {
}