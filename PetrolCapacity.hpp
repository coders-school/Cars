#pragma once

struct PetrolCapacity {
    using Type = double;

    PetrolCapacity() = default;
    
    static PetrolCapacity capacityCcm (long double ccm);

    operator Type() const;

private:
    PetrolCapacity(Type ccm);
    Type ccm = 0;
};

PetrolCapacity operator""_ccm (long double capacity);