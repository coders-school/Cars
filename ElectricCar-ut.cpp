#include "catch2.hpp"

#include "CarHaveMove.hpp"
#include "ElectricCar.hpp"
#include "PetrolEngine.hpp"
#include "WrongEngine.hpp"

SCENARIO("CorrectWorkElectricCar", "Cars"){
    GIVEN("ElectricCar"){
        ElectricCar tesla = new ElectricEngine(120, 700);

        WHEN("changePower"){
            THEN("shouldChangePower"){
                constexpr int newPower = 300;
                tesla.changeEngine(new ElectricEngine(newPower, 700));
                CHECK(tesla.getElectricPower() == newPower);
            }
        }
        WHEN("PutInCarPetrolEngine"){
            THEN("shouldThrowException"){
                CHECK_THROWS_AS(tesla.changeEngine(new PetrolEngine(300, 7.0, 5)), InvalidEngine);
                
            }
        }
        WHEN("changeChangeEngineDuringDriving"){
            THEN("shouldThrowException"){
                tesla.accelerate(100);
                CHECK_THROWS_AS(tesla.changeEngine(new ElectricEngine(100, 600)), MovingCar);
            }
        }
        WHEN("accelerate"){
            THEN("shouldAccelerate"){
                constexpr int newSpeed = 100;
                CHECK(tesla.getSpeed() == 0);
                tesla.accelerate(newSpeed);
                CHECK(tesla.getSpeed() == newSpeed);
            }
        }
        WHEN("brake"){
            THEN("shouldBrake"){
                tesla.brake();
                CHECK(tesla.getSpeed() == 0);
            }
        }
        WHEN("ChangeSpeedToInvalidValue"){
            THEN("shouldNotChande"){
                tesla.brake();
                CHECK(tesla.getSpeed() == 0);
                tesla.accelerate(-100);
                CHECK(tesla.getSpeed() == 0);
            }
        }
        WHEN("AccelerateToSpeedOutOfRange"){
            THEN("SpeedStopOn200"){
                tesla.accelerate(999);
                CHECK(tesla.getSpeed() == 200);
            }
        }
    }
}