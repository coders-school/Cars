#pragma once

#include "IEngine.hpp"
#include <gmock/gmock.h>

class EngineMock : public IEngine {

public:
  MOCK_CONST_METHOD0(start, void());
  MOCK_CONST_METHOD0(stop, void());
};
