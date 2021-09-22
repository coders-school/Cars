#include "ElectricCapacity.hpp"

ElectricCapacity::ElectricCapacity(unsigned long long int Ah) : Ah(Ah) {}

ElectricCapacity ElectricCapacity::capacityAh(unsigned long long int Ah) {
    return ElectricCapacity(Ah);
}

ElectricCapacity::operator unsigned long long int() const {
    return Ah;
}

ElectricCapacity operator""_Ah (unsigned long long int batteryCapacity) {
    return ElectricCapacity::capacityAh(batteryCapacity);
}