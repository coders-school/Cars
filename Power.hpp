#pragma once

struct Power {
    using Type = int;

    Power() = default;

    static Power powerHp(unsigned long long int hp);

    operator Type() const;

private:
    Power(Type power);
    Type hp = 0;
};

Power operator""_hp (unsigned long long int power);