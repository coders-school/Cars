#pragma once

struct Power {
    Power() = default;

    static Power powerHp(unsigned long long int hp);

    operator unsigned long long int() const;

private:
    Power(unsigned long long int power);
    unsigned long long int hp;  // in HP
};

Power operator""_hp (unsigned long long int power);
