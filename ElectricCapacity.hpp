#pragma once

struct ElectricCapacity {
    ElectricCapacity() = default;
    
    static ElectricCapacity capacityAh (unsigned long long int Ah);

    operator unsigned long long int () const;

private:
    ElectricCapacity(unsigned long long int Ah);
    unsigned long long int  Ah;  // in Ah
};

ElectricCapacity operator""_Ah (unsigned long long int batteryCapacity);