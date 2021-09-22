#include "Speed.hpp"

Speed::Speed(unsigned long long int value) : value(value) {}

Speed::operator unsigned long long int() const {
    return value;
}

Speed operator""_km_h (unsigned long long int value) {
    return Speed{value};
}

Speed operator""_mile_h (unsigned long long int value) {
    return Speed{static_cast<unsigned long long int>(value / 0.6213712)};
}
