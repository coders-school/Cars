#include "Power.hpp"

Power::Power(unsigned long long int power) : power(power) {}

Power::operator unsigned long long int() const {
    return power;
}

Power operator""_hp (unsigned long long int power) {
    return Power{power};
}