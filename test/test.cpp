#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"
#include "../Car.hpp"
#include "../ElectricCar.hpp"
#include "../ElectricEngine.hpp"
#include "../HybridCar.hpp"
#include "../PetrolCar.hpp"
#include "../PetrolEngine.hpp"


SCENARIO("Testing Electric car")
{
    GIVEN("New electric car from Tesla")
    {
        
        ElectricCar tesla(std::make_unique<ElectricEngine>(130, 650));
        Car* car = &tesla;
  
        WHEN("Checking if direction is changing")
        {
            REQUIRE(car->GetDirection() == "straight");

            THEN("Direction should be equal to left")
            {
                car->turnLeft();
                auto direction = car->GetDirection();
                CHECK( direction == "left");
            }
            THEN("Direction should be equal to right")
            {
                car->turnRight();
                auto direction = car->GetDirection();
                CHECK( direction == "right");
            }
        }

        WHEN("Checking if we can accelerate and then stop our super fast Tesla")
        {
            REQUIRE(car->GetSpeed() == 0);
            car->accelerate(70);
            THEN("Speed should be equal to 70")
            {   
                auto speed = car->GetSpeed();
                CHECK(speed == 70);
            }
            car->brake();
            THEN("Speed should be equal to 0")
            {   
                auto speed = car->GetSpeed();
                CHECK(speed == 0);
            }
        }
    }
}

// SCENARIO("Testing Petrol car")
// {
//     GIVEN("Two scenarios")
//     {
//         WHEN("Checking if it is possible to copy by copy constructor")
//         {
//             auto copy = std::is_copy_constructible<unique_ptr<int>>::value;
//             THEN("Result should be false")
//             {
//                 REQUIRE_FALSE(copy);
//             }
//         }
//         WHEN("Checking if it is possible to copy by copy assignment operator")
//         {
//             auto copy2 = std::is_copy_assignable<unique_ptr<int>>::value;
//             THEN("Result should be false")
//             {
//                 REQUIRE_FALSE(copy2);
//             }
//         }
//     }
// }

// SCENARIO("Testing Hybrid car")
// {
//     GIVEN("Two scenarios")
//     {
//         WHEN("Checking if it is possible to copy by copy constructor")
//         {
//             auto copy = std::is_copy_constructible<unique_ptr<int>>::value;
//             THEN("Result should be false")
//             {
//                 REQUIRE_FALSE(copy);
//             }
//         }
//         WHEN("Checking if it is possible to copy by copy assignment operator")
//         {
//             auto copy2 = std::is_copy_assignable<unique_ptr<int>>::value;
//             THEN("Result should be false")
//             {
//                 REQUIRE_FALSE(copy2);
//             }
//         }
//     }
// }