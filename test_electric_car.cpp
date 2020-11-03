#include "CarExceptions.hpp"
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "EngineMock.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class ElectricCarTestSuite : public ::testing::Test {
public:
  ElectricCarTestSuite()
    :   m_engineMock_electric_ptr(new EngineMock),
        m_engineMock_electric_rawPtr(m_engineMock_electric_ptr.get()),
        m_sut(std::move(m_engineMock_electric_ptr)) {}

  std::unique_ptr<EngineMock> m_engineMock_electric_ptr = nullptr;
  EngineMock *m_engineMock_electric_rawPtr = nullptr;
  ElectricCar m_sut;
};



TEST_F(ElectricCarTestSuite, stopEngineShouldCallStopOEngine) {
  EXPECT_CALL(*m_engineMock_electric_rawPtr, stop());
  m_sut.stop_engine();
}

TEST_F(ElectricCarTestSuite, startEngineShouldCallStopOEngine) {
  EXPECT_CALL(*m_engineMock_electric_rawPtr, start());
  m_sut.start_engine();
}



