#include "PetrolCapacity.hpp"

PetrolCapacity::PetrolCapacity(long double ccm) : ccm(ccm) {}

PetrolCapacity PetrolCapacity::capacityCcm (long double ccm) {
    return PetrolCapacity{ccm};
}

PetrolCapacity::operator long double() const {
    return ccm;
}

PetrolCapacity operator""_ccm (long double capacity) {
    return PetrolCapacity::capacityCcm(capacity);
}
