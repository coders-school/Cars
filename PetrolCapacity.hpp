#pragma once

struct PetrolCapacity {
    PetrolCapacity() = default;
    
    friend PetrolCapacity operator""_ccm (long double capacity);

    operator long double() const;

private:
    PetrolCapacity(long double capacity);
    long double capacity = 0; // in ccm
};

PetrolCapacity operator""_ccm (long double capacity);
