#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "EngineMock.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "CarExceptions.hpp"

struct CarTestSuite : public ::testing::Test
{
    EngineMock engineMock;
};

TEST_F(CarTestSuite, drivePetrolCar)
{
//how to tst with unique ptr?
    EXPECT_CALL(engineMock, start());
    EXPECT_CALL(engineMock, stop());

    PetrolCar opel(std::make_unique<EngineMock>(Power{120}, Capacity{1800}, Gears{6}));
    opel.accelerate(Speed{50});
    opel.brake();
    opel.refuel();
    opel.start_engine();
    opel.stop_engine();


}
TEST_F(CarTestSuite, WrongGear)
{
    PetrolEngine engine(Power{120}, Capacity{1800}, Gears{6});
    EXPECT_THROW(engine.changeGear(10), InvalidGear);
}
