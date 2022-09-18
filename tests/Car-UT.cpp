#include "Car.hpp"

#include "gtest/gtest.h"

// NOTE: we need to define testable class as Car is an abstract class
class CarTestable : public Car
{
  public:
    CarTestable(int maxSpeed, int maxReverseSpeed)
        : Car(maxSpeed, maxReverseSpeed)
    { }

    void refill() override { }
};

TEST(CarOnConstructionShould, throwWithNonPositiveMaxSpeedPassed)
{
    EXPECT_THROW((CarTestable { -20, -20 }), std::invalid_argument);
    EXPECT_THROW((CarTestable { 0, -10 }), std::invalid_argument);
}

TEST(CarOnConstructionShould, throwWithNonNegativeMaxReverseSpeedPassed)
{
    EXPECT_THROW((CarTestable { 120, 20 }), std::invalid_argument);
    EXPECT_THROW((CarTestable { 150, 0 }), std::invalid_argument);
}

TEST(CarOnConstructionShould, notThrowWithPositiveMaxSpeedAndNegativeMaxReverseSpeedPassed)
{
    EXPECT_NO_THROW((CarTestable { 120, -20 }));
    EXPECT_NO_THROW((CarTestable { 150, -150 }));
}

TEST(CarOnConstructionShould, initializeCurrentSpeedToZero)
{
    CarTestable sut(130, -10);

    EXPECT_EQ(sut.currentSpeed(), 0);
}

TEST(CarAccelerationShould, increaseCurrentSpeedToRequestedWhenNotReversingAndPositiveValuePassed)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);

    sut.accelerate(50);
    EXPECT_EQ(sut.currentSpeed(), 50);
}

TEST(CarAccelerationShould, stopTheCurrentSpeedAtMaxSpeedWhenMovingForwardIfExcessiveValuePassed)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);

    sut.accelerate(150);
    sut.accelerate(31);

    EXPECT_EQ(sut.currentSpeed(), 180);
}

TEST(CarAccelerationShould, doNotingIfCurrentSpeedPositiveAndNegativeValuePassed)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);

    sut.accelerate(150);
    sut.accelerate(31);

    EXPECT_EQ(sut.currentSpeed(), 180);
}

TEST(CarAccelerationShould, increaseNegativeSpeedWhenNotMovingForwardAndNegativeValuePassed)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);

    sut.accelerate(-10);
    EXPECT_EQ(sut.currentSpeed(), -10);
}

TEST(CarAccelerationShould, stopTheCurrentNegativeSpeedAtMaxReverseSpeedIfExcessiveValuePassed)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);

    sut.accelerate(-10);
    sut.accelerate(-30);
    EXPECT_EQ(sut.currentSpeed(), -20);
}

TEST(CarAccelerationShould, doNothingIfCurrentSpeedPositiveAndNegativeValuePassed)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);

    sut.accelerate(50);
    sut.accelerate(-30);
    EXPECT_EQ(sut.currentSpeed(), 50);
}

TEST(CarAccelerationShould, doNothingIfCurrentSpeedNegativeAndPositiveValuePassed)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);

    sut.accelerate(-10);
    sut.accelerate(50);
    EXPECT_EQ(sut.currentSpeed(), -10);
}

TEST(CarAccelerationShould, doNothingIfZeroPassed)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);
    // when reversing
    sut.accelerate(-10);
    sut.accelerate(0);
    EXPECT_EQ(sut.currentSpeed(), -10);

    CarTestable sut2(180, -20);
    EXPECT_EQ(sut2.currentSpeed(), 0);
    // when not moving
    sut2.accelerate(0);
    EXPECT_EQ(sut2.currentSpeed(), 0);
    // when moving forwrd;
    sut2.accelerate(30);
    sut2.accelerate(0);
    EXPECT_EQ(sut2.currentSpeed(), 30);
}

TEST(CarBrakeShould, setCurrentSpeedToZeroIfNoArgumentPassed)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);

    sut.accelerate(-15);

    sut.brake();
    EXPECT_EQ(sut.currentSpeed(), -0);
}

TEST(CarBrakeShould, setCurrentSpeedToDesiredPositiveValueWhenMovingForward)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);

    sut.accelerate(90);
    EXPECT_EQ(sut.currentSpeed(), 90);

    sut.brake(45);
    EXPECT_EQ(sut.currentSpeed(), 45);
}

TEST(CarBrakeShould, setCurrentSpeedToDesiredNegativeValueWhenReversing)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);

    sut.accelerate(-15);
    EXPECT_EQ(sut.currentSpeed(), -15);

    sut.brake(-5);
    EXPECT_EQ(sut.currentSpeed(), -5);
}

TEST(CarBrakeShould, doNothingIfRequestedPositiveValueIsHigherThanCurrentForwardSpeed)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);

    sut.accelerate(90);
    EXPECT_EQ(sut.currentSpeed(), 90);

    sut.brake(100);
    EXPECT_EQ(sut.currentSpeed(), 90);
}

TEST(CarBrakeShould, doNothingIfRequestedNegativeValueIsLowerThanCurrentForwardSpeed)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);

    sut.accelerate(-18);
    EXPECT_EQ(sut.currentSpeed(), -18);

    sut.brake(-25);
    EXPECT_EQ(sut.currentSpeed(), -18);
}

TEST(CarBrakeShould, doNothingIfMovingForwardAndNegativeValuePassed)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);

    sut.accelerate(70);
    EXPECT_EQ(sut.currentSpeed(), 70);

    sut.brake(-25);
    EXPECT_EQ(sut.currentSpeed(), 70);
}

TEST(CarBrakeShould, doNothingIfReversingAndPositiveValuePassed)
{
    CarTestable sut(180, -20);
    EXPECT_EQ(sut.currentSpeed(), 0);

    sut.accelerate(-18);
    EXPECT_EQ(sut.currentSpeed(), -18);

    sut.brake(25);
    EXPECT_EQ(sut.currentSpeed(), -18);
}
