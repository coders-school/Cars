#include "CarExceptions.hpp"
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "EngineMock.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class CarTestSuite : public ::testing::Test {
public:
  CarTestSuite()
      : m_engineMock_ptr(new EngineMock),
        m_engineMock_rawPtr(m_engineMock_ptr.get()),
        m_sut(std::move(m_engineMock_ptr)) {}

  std::unique_ptr<EngineMock> m_engineMock_ptr = nullptr;
  EngineMock *m_engineMock_rawPtr = nullptr;
  PetrolCar m_sut;
};

TEST_F(CarTestSuite, stopEngineShouldCallStopOEngine) {
  EXPECT_CALL(*m_engineMock_rawPtr, stop());
  m_sut.stop_engine();
}

TEST_F(CarTestSuite, startEngineShouldCallStopOEngine) {
  EXPECT_CALL(*m_engineMock_rawPtr, start());
  m_sut.start_engine();
}

TEST_F(CarTestSuite, WrongGear) {
  PetrolEngine engine(Power{120}, Capacity{1800}, Gears{6});
  EXPECT_THROW(engine.changeGear(10), InvalidGear);
}
