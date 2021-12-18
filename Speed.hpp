#pragma once

struct Speed {
    using Type = int;

    Speed() = default;
    static constexpr Type limit = 350;
    static Speed speedKmph(unsigned long long int kmph);

    operator Type() const;

private:
    Speed(Type kmph);
    Type kmph = 0;
};

Speed operator""_km_h (unsigned long long int kmph);