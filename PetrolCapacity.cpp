#include "PetrolCapacity.hpp"

PetrolCapacity::PetrolCapacity(long double capacity) : capacity(capacity) {}

PetrolCapacity::operator long double() const {
    return capacity;
}

PetrolCapacity operator""_ccm (long double capacity) {
    return PetrolCapacity{capacity};
}
