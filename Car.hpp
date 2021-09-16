#pragma once

#include <memory>

class PetrolEngine;
class ElectricEngine;

class Car {
public:
    struct Speed {
        explicit constexpr Speed(int speed)
            : val(speed) {}
        int val;
        bool operator!=(const Speed& other) const;
        bool operator>(const Speed& other) const;
        bool operator<(const Speed& other) const;
    };

    virtual ~Car();
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(const Speed& speed);
    Speed getSpeed() const;
    virtual void refill() = 0;
    virtual void changeEngine(std::unique_ptr<PetrolEngine> engine) = 0;
    virtual void changeEngine(std::unique_ptr<ElectricEngine> engine) = 0;

private:
    Speed speed_{0};
};
