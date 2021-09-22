#pragma once

struct ElectricCapacity {
    ElectricCapacity() = default;
    
    friend ElectricCapacity operator""_Ah (unsigned long long int batteryCapacity);

    operator unsigned long long int () const;

private:
    ElectricCapacity(unsigned long long int capabatteryCapacitycity);
    unsigned long long int  batteryCapacity;  // in Ah
};

ElectricCapacity operator""_Ah (unsigned long long int  batteryCapacity);