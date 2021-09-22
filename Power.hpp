#pragma once

struct Power {
    Power() = default;
    
    friend Power operator""_hp (unsigned long long int power);

    operator unsigned long long int() const;

private:
    Power(unsigned long long int power);
    unsigned long long int power;  // in HP
};

Power operator""_hp (unsigned long long int power);
