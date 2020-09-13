#include "catch2.hpp"

#include "CarHaveMove.hpp"
#include "InvalidGear.hpp"
#include "HybridCar.hpp"
#include "WrongEngine.hpp"

SCENARIO("CorrectWorkHybridCar", "Cars"){
    GIVEN("HybridCar"){
        HybridCar car(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
        WHEN("changeGear"){
            THEN("shouldChangeGear"){
                CHECK_NOTHROW(car.changeGear(5));
                CHECK(car.getCurrentGear() == 5);
            }
        }
        WHEN("gearOutOfRange"){
            THEN("shouldThrowException"){
                CHECK_THROWS_AS(car.changeGear(-2), InvalidGear);
                CHECK_THROWS_AS(car.changeGear(6), InvalidGear);
            }
        }
        WHEN("GearChangedToRFromHighGear"){
            THEN("shouldThrowException"){
                car.changeGear(2);
                CHECK_THROWS_AS(car.changeGear(-1), InvalidGear);
            }
        }

        WHEN("changePetrolPower"){
            THEN("shouldChangePower"){
                constexpr int newPower = 300;
                car.changeEngine(new PetrolEngine(newPower, 5.0, 5));
                CHECK(car.getPetrolPower() == newPower);
            }
        }

        WHEN("changeElectricPower"){
            THEN("shouldChangePower"){
                constexpr int newPower = 300;
                car.changeEngine(new ElectricEngine(newPower, 700));
                CHECK(car.getElectricPower() == newPower);
            }
        }
         WHEN("changeChangePetrolEngineDuringDriving"){
            THEN("shouldThrowException"){
                car.accelerate(100);
                CHECK_THROWS_AS(car.changeEngine(new PetrolEngine(100, 5.0, 3)), MovingCar);
            }
        }
        WHEN("changeChangeElectricEngineDuringDriving"){
            THEN("shouldThrowException"){
                car.accelerate(100);
                CHECK_THROWS_AS(car.changeEngine(new ElectricEngine(100, 600)), MovingCar);
            }
        }
        WHEN("accelerate"){
            THEN("shouldAccelerate"){
                constexpr int newSpeed = 100;
                CHECK(car.getSpeed() == 0);
                car.accelerate(newSpeed);
                CHECK(car.getSpeed() == newSpeed);
            }
        }
        WHEN("brake"){
            THEN("shouldBrake"){
                car.brake();
                CHECK(car.getSpeed() == 0);
            }
        }
        WHEN("ChangeSpeedToInvalidValue"){
            THEN("shouldNotChande"){
                car.brake();
                CHECK(car.getSpeed() == 0);
                car.accelerate(-100);
                CHECK(car.getSpeed() == 0);
            }
        }
        WHEN("AccelerateToSpeedOutOfRange"){
            THEN("SpeedStopOn200"){
                car.accelerate(999);
                CHECK(car.getSpeed() == 200);
            }
        }
    }
}