#include "ElectricCapacity.hpp"
#include <limits>
#include <stdexcept>

ElectricCapacity::ElectricCapacity(Type Ah) : Ah(Ah) {}

ElectricCapacity ElectricCapacity::capacityAh(unsigned long long int Ah) {
    if(Ah > std::numeric_limits<Type>::max()) {
        throw std::range_error("Error: electric capacity to high to be stored.");
    }
    return ElectricCapacity{static_cast<Type>(Ah)};
}

ElectricCapacity::operator Type() const {
    return Ah;
}

ElectricCapacity operator""_Ah (unsigned long long int batteryCapacity) {
    return ElectricCapacity::capacityAh(batteryCapacity);
}