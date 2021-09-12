#pragma once

class Car;

class Engine {
public:
    struct HorsePower {
        explicit HorsePower(int power)
            : val(power) {}
        int val;
    };

    Engine(HorsePower power);
    bool attach(const Car* const ptr);
    void detach();

private:
    HorsePower power_;
    const Car* car_{nullptr};
};