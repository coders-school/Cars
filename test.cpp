#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "EngineMock.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"


struct CarTestSuite : public ::testing::Test
{
    EngineMock engineMock;
};

TEST_F(CarTestSuite, drivePetrolCar)
{

    EXPECT_CALL(engineMock, start());
    EXPECT_CALL(engineMock, stop());

    PetrolCar opel(std::make_unique<PetrolEngine>(Power{120}, Capacity{1800}, Gears{6}));
    opel.accelerate(50);
    opel.brake();
    opel.accelerate(-900);
    opel.refuel();

}
