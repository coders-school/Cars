#include "CarExceptions.hpp"
#include "PetrolCar.hpp"

#include "gtest/gtest.h"

class PetrolCarTestable : public PetrolCar
{
  public:
    PetrolCarTestable(int maxSpeed, int maxReverseSpeed, const PetrolEngine& engine)
        : Car(maxSpeed, maxReverseSpeed)
        , PetrolCar(maxSpeed, maxReverseSpeed, engine)
    { }

    int enginePower() const
    {
        return engine_.power();
    }

    int engineCapacity() const
    {
        return engine_.capacity();
    }
};

TEST(PetrolCarRefillShould, throwOnAttemptToRefillWhenCarIsMoving)
{
    PetrolCarTestable sut(180, -25, PetrolEngine(120, 1800, 6));
    sut.accelerate(30);

    EXPECT_EQ(sut.currentSpeed(), 30);
    EXPECT_THROW(sut.refill(), RefillError);

    PetrolCarTestable sut2(140, -20, PetrolEngine(120, 1800, 6));
    sut2.accelerate(-10);

    EXPECT_EQ(sut2.currentSpeed(), -10);
    EXPECT_THROW(sut.refill(), RefillError);
}

TEST(PetrolCarRefillShould, notThrowOnAttemptToRefillWhenCarIsStopped)
{
    PetrolCarTestable sut(180, -25, PetrolEngine(120, 1800, 6));

    EXPECT_EQ(sut.currentSpeed(), 0);
    EXPECT_NO_THROW(sut.refill());
}

TEST(PetrolCarReplaceEngineShould, throwOnCallWhenCarIsNotStopped)
{
    PetrolCarTestable sut(180, -25, PetrolEngine(120, 1800, 6));
    sut.accelerate(30);

    PetrolEngine new_engine { 140, 2000, 6 };
    EXPECT_EQ(sut.currentSpeed(), 30);
    EXPECT_THROW(sut.replaceEngine(std::move(new_engine)), ReplaceEngineError);

    PetrolCarTestable sut2(180, -25, PetrolEngine(120, 1800, 6));
    sut2.accelerate(-10);

    PetrolEngine new_engine2 { 140, 2000, 6 };
    EXPECT_EQ(sut2.currentSpeed(), -10);
    EXPECT_THROW(sut2.replaceEngine(std::move(new_engine2)), ReplaceEngineError);
}

TEST(PetrolCarReplaceEngineShould, notThrowOnCallWhenCarIsStopped)
{
    PetrolCarTestable sut(180, -25, PetrolEngine(120, 1800, 6));

    PetrolEngine new_engine { 140, 2000, 6 };

    EXPECT_EQ(sut.currentSpeed(), 0);
    EXPECT_NO_THROW(sut.replaceEngine(std::move(new_engine)));
}

TEST(PetrolCarReplaceEngineShould, replaceEngineWhenCarIsStopped)
{
    PetrolCarTestable sut(180, -25, PetrolEngine(120, 1800, 6));
    int old_engine_power = sut.enginePower();
    int old_engine_capacity = sut.engineCapacity();

    PetrolEngine new_engine { 140, 2000, 6 };
    EXPECT_EQ(sut.currentSpeed(), 0);
    sut.replaceEngine(std::move(new_engine));

    EXPECT_NE(old_engine_power, sut.enginePower());
    EXPECT_NE(old_engine_capacity, sut.engineCapacity());
    EXPECT_EQ(sut.enginePower(), 140);
    EXPECT_EQ(sut.engineCapacity(), 2000);
}

TEST(PetrolCarReplaceEngineShould, notReplaceEngineWhenCarIsNotStopped)
{
    PetrolCarTestable sut(180, -25, PetrolEngine(120, 1800, 6));
    sut.accelerate(30);
    int old_engine_power = sut.enginePower();
    int old_engine_capacity = sut.engineCapacity();

    PetrolEngine new_engine { 140, 2000, 6 };
    EXPECT_EQ(sut.currentSpeed(), 30);
    EXPECT_THROW(sut.replaceEngine(std::move(new_engine)), ReplaceEngineError);
    EXPECT_EQ(old_engine_power, sut.enginePower());
    EXPECT_EQ(old_engine_capacity, sut.engineCapacity());

    PetrolCarTestable sut2(180, -25, PetrolEngine(120, 1800, 6));
    sut2.accelerate(-10);
    int old_engine_power2 = sut2.enginePower();
    int old_engine_capacity2 = sut2.engineCapacity();

    PetrolEngine new_engine2 { 140, 2000, 6 };
    EXPECT_EQ(sut2.currentSpeed(), -10);
    EXPECT_THROW(sut2.replaceEngine(std::move(new_engine2)), ReplaceEngineError);
    EXPECT_EQ(old_engine_power2, sut.enginePower());
    EXPECT_EQ(old_engine_capacity2, sut.engineCapacity());
}
