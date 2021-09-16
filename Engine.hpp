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

protected:
    const Car* car_{nullptr};

private:
    HorsePower power_;
};