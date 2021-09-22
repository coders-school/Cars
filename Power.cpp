#include "Power.hpp"

Power::Power(unsigned long long int hp) : hp(hp) {}

Power Power::powerHp(unsigned long long int hp) {
    return Power(hp);
}

Power::operator unsigned long long int() const {
    return hp;
}

Power operator""_hp (unsigned long long int power) {
    return Power::powerHp(power);
}