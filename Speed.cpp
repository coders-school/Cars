#include "Speed.hpp"
#include <limits>
#include <stdexcept>

Speed::Speed(Type kmph) : kmph(kmph) {}

Speed Speed::speedKmph(unsigned long long int kmph) {
    if(kmph > std::numeric_limits<Type>::max()) {
        throw std::range_error("Error: speed to high to be stored.");
    }
    return Speed{static_cast<Type>(kmph)};
}

Speed Speed::speedMph(unsigned long long int mph) {
    if(mph > std::numeric_limits<Type>::max() * 0.6213712) {
        throw std::range_error("Error: speed to high to be stored.");
    }
    return Speed(static_cast<Type>(mph / 0.6213712));
}

Speed::operator Type() const {
    return kmph;
}

Speed operator""_km_h (unsigned long long int kmph) {
    return Speed::speedKmph(kmph);
}

Speed operator""_mile_h (unsigned long long int mph) {
    return Speed::speedMph(mph);
}
