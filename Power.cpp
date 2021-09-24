#include "Power.hpp"
#include <limits>
#include <stdexcept>

Power::Power(Type hp) : hp(hp) {}

Power Power::powerHp(unsigned long long int hp) {
    if(hp > std::numeric_limits<Type>::max()) {
        throw std::range_error("Error: Petrol capacity to high to be stored.");
    }
    return Power{static_cast<Type>(hp)};
}

Power::operator Type() const {
    return hp;
}

Power operator""_hp (unsigned long long int power) {
    return Power::powerHp(power);
}