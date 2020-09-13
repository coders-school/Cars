#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2.hpp"

#include "CarHaveMove.hpp"
#include "ElectricEngine.hpp"
#include "InvalidGear.hpp"
#include "PetrolCar.hpp"
#include "WrongEngine.hpp"



SCENARIO("CorrectWorkPetrolCar", "Cars"){
    GIVEN("PetrolCar"){
        PetrolCar opel = new PetrolEngine(400, 5.0, 5);

        WHEN("changeGear"){
            THEN("shouldChangeGear"){
                CHECK_NOTHROW(opel.changeGear(5));
                CHECK(opel.getCurrentGear() == 5);
            }
        }
        WHEN("gearOutOfRange"){
            THEN("shouldThrowException"){
                CHECK_THROWS_AS(opel.changeGear(-2), InvalidGear);
                CHECK_THROWS_AS(opel.changeGear(6), InvalidGear);
            }
        }
        WHEN("GearChangedToRFromHighGear"){
            THEN("shouldThrowException"){
                opel.changeGear(2);
                CHECK_THROWS_AS(opel.changeGear(-1), InvalidGear);
            }
        }
        WHEN("changePower"){
            THEN("shouldChangePower"){
                constexpr int newPower = 300;
                opel.changeEngine(new PetrolEngine(newPower, 5.0, 5));
                CHECK(opel.getPetrolPower() == newPower);
            }
        }
        WHEN("PutInCarElectricEngine"){
            THEN("shouldThrowException"){
                CHECK_THROWS_AS(opel.changeEngine(new ElectricEngine(300, 700)), InvalidEngine);
                
            }
        }
        WHEN("changeChangeEngineDuringDriving"){
            THEN("shouldThrowException"){
                opel.accelerate(100);
                CHECK_THROWS_AS(opel.changeEngine(new PetrolEngine(100, 5.0, 3)), MovingCar);
            }
        }
        WHEN("brake"){
            THEN("shouldBrake"){
                opel.brake();
                CHECK(opel.getSpeed() == 0);
            }
        }
        WHEN("accelerate"){
            THEN("shouldAccelerate"){
                constexpr int newSpeed = 100;
                CHECK(opel.getSpeed() == 0);
                opel.accelerate(newSpeed);
                CHECK(opel.getSpeed() == newSpeed);
            }
        }
        WHEN("ChangeSpeedToInvalidValue"){
            THEN("shouldNotChande"){
                opel.brake();
                CHECK(opel.getSpeed() == 0);
                opel.accelerate(-100);
                CHECK(opel.getSpeed() == 0);
            }
        }
        WHEN("AccelerateToSpeedOutOfRange"){
            THEN("SpeedStopOn200"){
                opel.accelerate(999);
                CHECK(opel.getSpeed() == 200);
            }
        }
    }
}