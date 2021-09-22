#pragma once

struct Speed {
    Speed() = default;

    friend Speed operator""_km_h (unsigned long long int value);
    friend Speed operator""_mile_h (unsigned long long int value);

    operator unsigned long long int() const;

private:
    Speed(unsigned long long int value);
    unsigned long long int value = 0; //km per h
};

Speed operator""_km_h (unsigned long long int value);
Speed operator""_mile_h (unsigned long long int value);
