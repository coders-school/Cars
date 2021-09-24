#pragma once

struct Speed {
    using Type = int; 

    Speed() = default;

    static Speed speedKmph(unsigned long long int kmph);
    static Speed speedMph(unsigned long long int mph);

    operator Type() const;

private:
    Speed(Type kmph);
    Type kmph = 0;
};

Speed operator""_km_h (unsigned long long int kmph);
Speed operator""_mile_h (unsigned long long int mph);
