#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "EngineMock.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "CarExceptions.hpp"


TEST(CarTestSuite, stopEngineShouldCallStopOEngine)
{
    std::unique_ptr<EngineMock> engineMock_ptr(new EngineMock());
    EngineMock* engineMock_rawPtr = engineMock_ptr.get();
    PetrolCar m_sut(std::move(engineMock_ptr));
    EXPECT_CALL(*engineMock_rawPtr, stop());
    m_sut.stop_engine();
}

TEST(CarTestSuite, startEngineShouldCallStopOEngine)
{
    std::unique_ptr<EngineMock> engineMock_ptr(new EngineMock());
    EngineMock* engineMock_rawPtr = engineMock_ptr.get();
    PetrolCar m_sut(std::move(engineMock_ptr));
    EXPECT_CALL(*engineMock_rawPtr, start());
    m_sut.start_engine();
}

TEST(CarTestSuite, WrongGear)
{
    PetrolEngine engine(Power{120}, Capacity{1800}, Gears{6});
    EXPECT_THROW(engine.changeGear(10), InvalidGear);
}
