#include "Speed.hpp"
#include <limits>
#include <stdexcept>

Speed::Speed(Type kmph) : kmph(kmph) {}

Speed Speed::speedKmph(unsigned long long int kmph) {
    if(kmph > static_cast<decltype(kmph)>(std::numeric_limits<Type>::max())) {
        throw std::range_error("Error: speed to high to be stored.");
    }
    if(kmph > static_cast<decltype(kmph)>(limit)) {
        throw std::range_error("Error: speed higher than limit.");
    }
    return Speed{static_cast<Type>(kmph)};
}

Speed::operator Type() const {
    return kmph;
}

Speed operator""_km_h (unsigned long long int kmph) {
    return Speed::speedKmph(kmph);
}
