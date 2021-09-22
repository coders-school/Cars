#pragma once

struct PetrolCapacity {
    PetrolCapacity() = default;
    
    static PetrolCapacity capacityCcm (long double ccm);

    operator long double() const;

private:
    PetrolCapacity(long double ccm);
    long double ccm = 0; // in ccm
};

PetrolCapacity operator""_ccm (long double capacity);
