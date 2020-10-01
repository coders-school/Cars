#pragma once

#include <gmock/gmock.h>
#include "IEngine.hpp"

class EngineMock : public IEngine
{

public:
    MOCK_CONST_METHOD0(start, void());
    MOCK_CONST_METHOD0(stop, void());
};
