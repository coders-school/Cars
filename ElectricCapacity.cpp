#include "ElectricCapacity.hpp"

ElectricCapacity::ElectricCapacity(unsigned long long int batteryCapacity) : batteryCapacity(batteryCapacity) {}

ElectricCapacity::operator unsigned long long int() const {
    return batteryCapacity;
}

ElectricCapacity operator""_Ah (unsigned long long int batteryCapacity) {
    return ElectricCapacity{batteryCapacity};
}