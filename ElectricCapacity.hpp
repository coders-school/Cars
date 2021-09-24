#pragma once

struct ElectricCapacity {
    using Type = int;

    ElectricCapacity() = default;
    
    static ElectricCapacity capacityAh (unsigned long long int Ah);

    operator Type() const;

private:
    ElectricCapacity(Type Ah);
    Type Ah = 0;
};

ElectricCapacity operator""_Ah (unsigned long long int batteryCapacity);