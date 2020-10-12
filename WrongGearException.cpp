#include "WrongGearException.hpp"
#include <algorithm>

WrongGearException::WrongGearException(const int gear, const int gears)
    :logic_error("Exception: You choose: " + std::to_string(gear) +
          " when having only " + std::to_string(gears) + "!\n"){}

