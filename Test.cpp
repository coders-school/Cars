#include <catch2/catch_all.hpp>
#include "InvalidGear.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

int power = 10;
float capacity = 10;
int gears = 5;

SCENARIO("Legal gear change.", "[gear][legal]") {
    GIVEN("Petrol car gear legal changes.") {
        PetrolCar car(std::make_unique<PetrolEngine>(power, capacity, gears));
        int startgear = GENERATE(0, 1, 2, 3, gears);
        car.changeGear(startgear);
        WHEN("Change gear from " << startgear) {
            int nextGear = GENERATE(0, 1, 2, 3, gears);
            THEN("Throw exception when changed to " << nextGear) {
                REQUIRE_NOTHROW(car.changeGear(nextGear));
            }
        }
    }
}

SCENARIO("Illegal gear change.", "[gear]") {
    GIVEN("Petrol car witch R gear set.") {
        PetrolCar car(std::make_unique<PetrolEngine>(power, capacity, gears));
        WHEN("Change gear") {
            car.changeGear(-1);
            int nextGear = GENERATE(1, gears, gears + 1, std::numeric_limits<int>::max());
            THEN("Throw exception when changed to " << nextGear) {
                REQUIRE_THROWS_AS(car.changeGear(nextGear), InvalidGear);
            }
        }
    }

    GIVEN("Petrol car witch 1 gear set.") {
        PetrolCar car(std::make_unique<PetrolEngine>(power, capacity, gears));
        WHEN("Change gear") {
            car.changeGear(1);
            int nextGear = GENERATE(-1, -gears, -gears - 1, std::numeric_limits<int>::min());
            THEN("Throw exception when changed to " << nextGear) {
                REQUIRE_THROWS_AS(car.changeGear(nextGear), InvalidGear);
            }
        }
    }
}

constexpr auto maxSpeed = 350;

SCENARIO("Illegal accelerate speed.", "[accelerate]") {
    GIVEN("Petrol car witch R gear set.") {
        Car car;
        WHEN("accelerate speed") {
            int speed = GENERATE(0, 1, maxSpeed);
            THEN("no exception when accelerate to " << speed) {
                REQUIRE_NOTHROW(car.accelerate(speed));
            }
        }

        WHEN("accelerate speed") {
            int speed = GENERATE(-1, -maxSpeed);
            THEN("no exception when accelerate to " << speed) {
                REQUIRE_THROWS(car.accelerate(speed));
            }
        }
    }
}