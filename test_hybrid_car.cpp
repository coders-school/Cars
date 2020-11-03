#include "CarExceptions.hpp"
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "EngineMock.hpp"
#include "HybridCar.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

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



