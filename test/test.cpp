#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"
#include "../Car.hpp"
#include "../ElectricCar.hpp"
#include "../ElectricEngine.hpp"
#include "../HybridCar.hpp"
#include "../PetrolCar.hpp"
#include "../PetrolEngine.hpp"


// SCENARIO("Testing Electric car")
// {
//     GIVEN("")
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