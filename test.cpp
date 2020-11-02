#include "CarExceptions.hpp"
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "EngineMock.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class PetrolCarTestSuite : public ::testing::Test {
public:
  PetrolCarTestSuite()
      : m_engineMock_ptr(new EngineMock),
        m_engineMock_rawPtr(m_engineMock_ptr.get()),
        m_sut(std::move(m_engineMock_ptr)) {}

  std::unique_ptr<EngineMock> m_engineMock_ptr = nullptr;
  EngineMock *m_engineMock_rawPtr = nullptr;
  PetrolCar m_sut;
};


class HybridCarTestSuite : public ::testing::Test {
public:
  HybridCarTestSuite()
      : m_engineMock_petrol_ptr(new EngineMock),
        m_engineMock_electric_ptr(new EngineMock),
        m_engineMock_petrol_rawPtr(m_engineMock_petrol_ptr.get()),
        m_engineMock_electric_rawPtr(m_engineMock_electric_ptr.get()),
        m_sut(std::move(m_engineMock_petrol_ptr),std::move(m_engineMock_electric_ptr)) {}

  std::unique_ptr<EngineMock> m_engineMock_petrol_ptr = nullptr;
  std::unique_ptr<EngineMock> m_engineMock_electric_ptr = nullptr;
  EngineMock *m_engineMock_petrol_rawPtr = nullptr;
  EngineMock *m_engineMock_electric_rawPtr = nullptr;
  HybridCar m_sut;
};


TEST_F(PetrolCarTestSuite, stopEngineShouldCallStopOEngine) {
  EXPECT_CALL(*m_engineMock_rawPtr, stop());
  m_sut.stop_engine();
}

TEST_F(PetrolCarTestSuite, startEngineShouldCallStopOEngine) {
  EXPECT_CALL(*m_engineMock_rawPtr, start());
  m_sut.start_engine();
}

TEST(EngineTestSuite, WrongGear) {
  PetrolEngine engine(Power{120}, Capacity{1800}, Gears{6});
  EXPECT_THROW(engine.changeGear(10), InvalidGear);
}

TEST(EngineTestSuite, ProperGear) {
  PetrolEngine engine(Power{120}, Capacity{1800}, Gears{6});
  engine.changeGear(-1);
  EXPECT_EQ(engine.currentGear_, -1);
  engine.changeGear(0);
  engine.changeGear(1);
  EXPECT_EQ(engine.currentGear_, 1);
}

TEST_F(HybridCarTestSuite, stopEngineShouldCallStopOEngine) {
  EXPECT_CALL(*m_engineMock_petrol_rawPtr, stop());
  EXPECT_CALL(*m_engineMock_electric_rawPtr, stop());
  m_sut.stop_engine();
}

TEST_F(HybridCarTestSuite, startEngineShouldCallStopOEngine) {
  EXPECT_CALL(*m_engineMock_petrol_rawPtr, start());
  EXPECT_CALL(*m_engineMock_electric_rawPtr, start());
  m_sut.start_engine();
}



