// #include "ElectricEngine.hpp"
// #include "Exceptions.hpp"
// #include "gtest/gtest.h"
// #include "HybridCar.hpp"
// #include "PetrolEngine.hpp"

// constexpr int enginePower = 186;
// constexpr int engineCapacity = 1998.9;
// constexpr int gears = 5;
// constexpr int maxFuelTank = 180;

// constexpr int newEnginePower = 320;
// constexpr int newEngineCapacity = 2499.5;
// constexpr int newGears = 6;

// class HybridTestCar : public ::testing::Test {
// protected:
//     HybridTestCar()
//         : HybridCar(std::make_unique<PetrolEngine>(enginePower, engineCapacity, gears, maxFuelTank)){};
//     HybridCar HybridCar;
// };

// TEST_F(HybridTestCar, HybridCarCanAccelerateBy30) {
//     EXPECT_NO_THROW(HybridCar.accelerate(30));
// }

// TEST_F(HybridTestCar, HybridCarCANTAccelerateBy30Below0) {
//     EXPECT_THROW(HybridCar.accelerate(-30), InvalidSpeed);
// }

// TEST_F(HybridTestCar, HybridCarCanDecelerateBy30AfterAccelerateBy50) {
//     HybridCar.accelerate(50);
//     EXPECT_NO_THROW(HybridCar.decelerate(30));
// }

// TEST_F(HybridTestCar, HybridCarCANTDecelerateBy30AfterAccelerateBy20) {
//     HybridCar.accelerate(20);
//     EXPECT_THROW(HybridCar.decelerate(30), InvalidSpeed);
// }

// TEST_F(HybridTestCar, HybridCarCANTDecelerateBy30Below0AfterAccelerateBy20) {
//     HybridCar.accelerate(20);
//     EXPECT_THROW(HybridCar.decelerate(-30), InvalidSpeed);
// }

// TEST_F(HybridTestCar, HybridCarCanChangeEngineAfterStop) {
//     HybridCar.brake();
//     EXPECT_NO_THROW(HybridCar.changePetrolEngine(std::make_unique<PetrolEngine>(newEnginePower,
//                                                                                 newEngineCapacity,
//                                                                                 newGears,
//                                                                                 maxFuelTank)));
// }

// TEST_F(HybridTestCar, HybridCarCANTChangeEngineWhileItIstMoving) {
//     HybridCar.accelerate(100);
//     EXPECT_THROW(HybridCar.changePetrolEngine(std::make_unique<PetrolEngine>(newEnginePower,
//                                                                              newEngineCapacity, 
//                                                                              newGears,
//                                                                              maxFuelTank)), 
//                                                                              InvalidSpeed);
// }

// TEST_F(HybridTestCar, HybridCarCanChargeWhenHasLowerBatteryCapacityThanengineCapacity) {
//     EXPECT_NO_THROW(HybridCar.restore());
// }

// TEST_F(HybridTestCar, HybridCarCANTChargeWhenItsFull) {
//     HybridCar.restore();
//     EXPECT_THROW(HybridCar.restore(), InvalidRestore);
// }

// TEST_F(HybridTestCar, HybridCarCanChangeTheGear) {
//     EXPECT_NO_THROW(HybridCar.changeGear(-1));
//     EXPECT_NO_THROW(HybridCar.changeGear(0));
//     EXPECT_NO_THROW(HybridCar.changeGear(6));
// }

// TEST_F(HybridTestCar, HybridCarCANTChargeTheWrongGear) {
//     EXPECT_THROW(HybridCar.changeGear(-2), InvalidGear);
//     EXPECT_THROW(HybridCar.changeGear(7), InvalidGear);
// }
