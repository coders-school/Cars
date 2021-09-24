#include "PetrolCapacity.hpp"
#include <limits>
#include <stdexcept>

PetrolCapacity::PetrolCapacity(Type ccm) : ccm(ccm) {}

PetrolCapacity PetrolCapacity::capacityCcm (long double ccm) {
    if(ccm > std::numeric_limits<Type>::max()) {
        throw std::range_error("Error: Petrol capacity to high to be stored.");
    }
    if(ccm < std::numeric_limits<Type>::min()) {
        throw std::range_error("Error: Petrol capacity to low to be stored.");
    }
    return PetrolCapacity{static_cast<Type>(ccm)};
}

PetrolCapacity::operator Type() const {
    return ccm;
}

PetrolCapacity operator""_ccm (long double capacity) {
    return PetrolCapacity::capacityCcm(capacity);
}
