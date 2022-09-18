#include "CarExceptions.hpp"
#include "ElectricCar.hpp"

#include "gtest/gtest.h"

class ElectricCarTestable : public ElectricCar
{
  public:
    ElectricCarTestable(int maxSpeed, int maxReverseSpeed, const ElectricEngine& engine)
        : Car(maxSpeed, maxReverseSpeed)
        , ElectricCar(maxSpeed, maxReverseSpeed, engine)
    { }

    int enginePower() const
    {
        return engine_.power();
    }

    int batteryCapacity() const
    {
        return engine_.batteryCapacity();
    }
};

TEST(ElectricCarRefillShould, throwOnAttemptToRefillWhenCarIsMoving)
{
    ElectricCarTestable sut(180, -25, ElectricEngine(130, 650));
    sut.accelerate(30);

    EXPECT_EQ(sut.currentSpeed(), 30);
    EXPECT_THROW(sut.refill(), RefillError);

    ElectricCarTestable sut2(140, -20, ElectricEngine(120, 600));
    sut2.accelerate(-10);

    EXPECT_EQ(sut2.currentSpeed(), -10);
    EXPECT_THROW(sut.refill(), RefillError);
}

TEST(ElectricCarRefillShould, notThrowOnAttemptToRefillWhenCarIsStopped)
{
    ElectricCarTestable sut(180, -25, ElectricEngine(130, 650));

    EXPECT_EQ(sut.currentSpeed(), 0);
    EXPECT_NO_THROW(sut.refill());
}

TEST(ElectricCarReplaceEngineShould, throwOnCallWhenCarIsNotStopped)
{
    ElectricCarTestable sut(180, -25, ElectricEngine(130, 650));
    sut.accelerate(30);

    ElectricEngine new_engine { 140, 700 };
    EXPECT_EQ(sut.currentSpeed(), 30);
    EXPECT_THROW(sut.replaceEngine(std::move(new_engine)), ReplaceEngineError);

    ElectricCarTestable sut2(180, -25, ElectricEngine(130, 650));
    sut2.accelerate(-10);

    ElectricEngine new_engine2 { 140, 700 };
    EXPECT_EQ(sut2.currentSpeed(), -10);
    EXPECT_THROW(sut2.replaceEngine(std::move(new_engine2)), ReplaceEngineError);
}

TEST(ElectricCarReplaceEngineShould, notThrowOnCallWhenCarIsStopped)
{
    ElectricCarTestable sut(180, -25, ElectricEngine(130, 650));

    ElectricEngine new_engine { 140, 700 };

    EXPECT_EQ(sut.currentSpeed(), 0);
    EXPECT_NO_THROW(sut.replaceEngine(std::move(new_engine)));
}

TEST(ElectricCarReplaceEngineShould, replaceEngineWhenCarIsStopped)
{
    ElectricCarTestable sut(180, -25, ElectricEngine(130, 650));
    int old_engine_power = sut.enginePower();
    int old_battery_capacity = sut.batteryCapacity();

    ElectricEngine new_engine { 140, 700 };
    EXPECT_EQ(sut.currentSpeed(), 0);
    sut.replaceEngine(std::move(new_engine));

    EXPECT_NE(old_engine_power, sut.enginePower());
    EXPECT_NE(old_battery_capacity, sut.batteryCapacity());
    EXPECT_EQ(sut.enginePower(), 140);
    EXPECT_EQ(sut.batteryCapacity(), 700);
}

TEST(ElectricCarReplaceEngineShould, notReplaceEngineWhenCarIsNotStopped)
{
    ElectricCarTestable sut(180, -25, ElectricEngine(130, 650));
    sut.accelerate(30);
    int old_engine_power = sut.enginePower();
    int old_battery_capacity = sut.batteryCapacity();

    ElectricEngine new_engine { 140, 700 };
    EXPECT_EQ(sut.currentSpeed(), 30);
    EXPECT_THROW(sut.replaceEngine(std::move(new_engine)), ReplaceEngineError);
    EXPECT_EQ(old_engine_power, sut.enginePower());
    EXPECT_EQ(old_battery_capacity, sut.batteryCapacity());

    ElectricCarTestable sut2(180, -25, ElectricEngine(130, 650));
    sut2.accelerate(-10);
    int old_engine_power2 = sut2.enginePower();
    int old_battery_capacity2 = sut2.batteryCapacity();

    ElectricEngine new_engine2 { 140, 700 };
    EXPECT_EQ(sut2.currentSpeed(), -10);
    EXPECT_THROW(sut2.replaceEngine(std::move(new_engine2)), ReplaceEngineError);
    EXPECT_EQ(old_engine_power2, sut.enginePower());
    EXPECT_EQ(old_battery_capacity2, sut.batteryCapacity());
}