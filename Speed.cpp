#include "Speed.hpp"

Speed::Speed(unsigned long long int kmph) : kmph(kmph) {}

Speed Speed::speedKmph(unsigned long long int kmph) {
    return Speed(kmph);
}

Speed Speed::speedMph(unsigned long long int mph) {
    return Speed(static_cast<unsigned long long int>(mph / 0.6213712));
}

Speed::operator unsigned long long int() const {
    return kmph;
}

Speed operator""_km_h (unsigned long long int kmph) {
    return Speed::speedKmph(kmph);
}

Speed operator""_mile_h (unsigned long long int mph) {
    return Speed::speedMph(mph);
}
