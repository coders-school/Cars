#pragma once

class Engine {
public:
    struct HorsePower {
        explicit HorsePower(int hp)
            : hp_(hp) {}
        int hp_;
    };

    Engine(HorsePower power);

private:
    HorsePower power_;
};