#pragma once

class Engine {
public:
    struct HorsePower {
        explicit HorsePower(int power)
            : val(power) {}
        int val;
    };

    Engine(HorsePower power);

private:
    HorsePower power_;
};