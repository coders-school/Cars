#pragma once

struct Speed {
    Speed() = default;

    static Speed speedKmph(unsigned long long int kmph);
    static Speed speedMph(unsigned long long int mph);

    operator unsigned long long int() const;

private:
    Speed(unsigned long long int kmph);
    unsigned long long int kmph = 0; // km/h
};

Speed operator""_km_h (unsigned long long int kmph);
Speed operator""_mile_h (unsigned long long int mph);
