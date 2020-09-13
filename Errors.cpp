#include "Errors.hpp"

ToLowSpeedError ::
    ToLowSpeedError(std::string speed)
    : std::logic_error("To Low Speed Error - speed " + speed + " cannot be set for this car.") {}

ToHighSpeedError ::ToHighSpeedError(std::string speed)
    : std::logic_error("To High Speed Error - speed " + speed + " cannot be set for this car.") {}

AccelerateToLoweSpeedError ::AccelerateToLoweSpeedError(std::string speed)
    : std::logic_error("You cannot accelerato to lower speed than actual (" + speed + ").") {}

BreakeToHigherSpeedError ::BreakeToHigherSpeedError(std::string speed)
    : std::logic_error("You cannot breake to higher speed than actual (" + speed + ").") {}

InvalidGearError::InvalidGearError(std::string gear)
    : std::logic_error("Invalid Gear - REAR gear cannot be set from " + gear + " gear.") {}
