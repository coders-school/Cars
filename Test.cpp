#include <catch2/catch_all.hpp>
#include "InvalidGear.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include "Speed.hpp"
#include <map>

auto power = 10_hp;
auto capacity = 10.0_ccm;
auto gears = ManualGear::g_5th;

std::map<ManualGear, std::string> gearNames = {
    {ManualGear::reverse, "reverse"},
    {ManualGear::neutral, "neutral"},
    {ManualGear::g_1st, "g_1st"},
    {ManualGear::g_2nd, "g_2nd"},
    {ManualGear::g_3th, "g_3th"},
    {ManualGear::g_4th, "g_4th"},
    {ManualGear::g_5th, "g_5th"},
    {ManualGear::g_6th, "g_6th"},
    {ManualGear::g_7th, "g_7th"},
    {ManualGear::g_8th, "g_8th"},
    {ManualGear::g_9th, "limit"},
};

SCENARIO("Legal gear change.", "[gear][legal]") {
    GIVEN("Petrol car gear legal changes.") {
        PetrolCar car(std::make_unique<PetrolEngine>(power, capacity, gears));
        auto startgear = GENERATE(ManualGear::neutral, ManualGear::g_1st, ManualGear::g_2nd, ManualGear::g_3th, gears);
        car.changeGear(startgear);
        auto nextGear = GENERATE(ManualGear::neutral, ManualGear::g_1st, ManualGear::g_2nd, ManualGear::g_3th, gears);
        WHEN("Change gear from " << gearNames[startgear] << " to " << gearNames[nextGear]) {
            THEN("Throw exception") {
                REQUIRE_NOTHROW(car.changeGear(nextGear));
            }
        }
    }

    GIVEN("Petrol car gear neutral.") {
        PetrolCar car(std::make_unique<PetrolEngine>(power, capacity, gears));
        car.changeGear(ManualGear::neutral);
        WHEN("Change gear to " << gearNames[ManualGear::reverse]) {
            THEN("Dont throw exception") {
                REQUIRE_NOTHROW(car.changeGear(ManualGear::reverse));
            }
        }
    }

    GIVEN("Petrol car gear reverse.") {
        PetrolCar car(std::make_unique<PetrolEngine>(power, capacity, gears));
        car.changeGear(ManualGear::reverse);
        WHEN("Change gear to " << gearNames[ManualGear::neutral]) {
            THEN("Dont throw exception") {
                REQUIRE_NOTHROW(car.changeGear(ManualGear::neutral));
            }
        }
    }
}

SCENARIO("Illegal gear change.", "[gear]") {
    GIVEN("Petrol car witch reverse gear set.") {
        PetrolCar car(std::make_unique<PetrolEngine>(power, capacity, gears));
        car.changeGear(ManualGear::reverse);
        auto nextGear = GENERATE(ManualGear::g_1st, ManualGear::g_2nd, ManualGear::g_3th, gears/*, ManualGear::Limit*/);
        WHEN("Change gear to " << gearNames[nextGear]) {
            THEN("Throw exception") {
                REQUIRE_THROWS_AS(car.changeGear(nextGear), InvalidGear);
            }
        }
    }

    GIVEN("Petrol car with gear set.") {
        PetrolCar car(std::make_unique<PetrolEngine>(power, capacity, gears));
        auto startgear = GENERATE(ManualGear::g_1st, ManualGear::g_2nd, ManualGear::g_3th, gears/*, ManualGear::Limit*/);
        car.changeGear(startgear);
        WHEN("Change gear from " << gearNames[startgear] << " to " << gearNames[ManualGear::reverse]) {
            THEN("Throw exception") {
                REQUIRE_THROWS_AS(car.changeGear(ManualGear::reverse), InvalidGear);
            }
        }
    }

    GIVEN("Petrol car with gear set.") {
        PetrolCar car(std::make_unique<PetrolEngine>(power, capacity, gears));
        auto startgear = GENERATE(ManualGear::reverse, ManualGear::neutral, ManualGear::g_1st, ManualGear::g_2nd, ManualGear::g_3th, gears);
        car.changeGear(startgear);
        WHEN("Change gear from " << gearNames[startgear] << " to " << gearNames[ManualGear::Limit]) {
            THEN("Throw exception") {
                REQUIRE_THROWS_AS(car.changeGear(ManualGear::Limit), InvalidGear);
            }
        }
    }
}

SCENARIO("Legal accelerate speed.", "[accelerate]") {
    GIVEN("Car.") {
        Car car;
        auto speed = GENERATE(0_km_h, 1_km_h, Speed::speedKmph(Speed::limit));
        WHEN("accelerate speed to " << speed) {
            THEN("no exception when accelerate to " << speed) {
                REQUIRE_NOTHROW(car.accelerate(speed));
            }
        }
    }
}

SCENARIO("Ilegal accelerate speed.", "[accelerate]") {
    GIVEN("Speed value to high to be stored.") {
        auto toHighSpeedValue = static_cast<unsigned long long int>(std::numeric_limits<int>::max()) + 1;
        WHEN("create speed of " << toHighSpeedValue) {
            THEN("no exception when accelerate to " << toHighSpeedValue) {
                REQUIRE_THROWS_AS(Speed::speedKmph(toHighSpeedValue), std::range_error);
            }
        }
    }

    GIVEN("Speed value higher than limit") {
        auto speed = GENERATE(Speed::limit + 1, 
                std::numeric_limits<int>::max());
        WHEN("accelerate speed to " << speed) {
            THEN("Exception throw.") {
                REQUIRE_THROWS_AS(Speed::speedKmph(speed), std::range_error);
            }
        }
    }
}