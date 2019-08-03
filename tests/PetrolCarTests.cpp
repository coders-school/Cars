#include <gtest/gtest.h>
#include "../PetrolCar.hpp"
#include "../Gear.hpp"
#include "../Exceptions.hpp"

TEST(PetrolCarTests, 
	ShouldHaveVelocityEqualToZeroAfterCreation)
{
	//TODO: prevent creating car with no engine
	PetrolCar pc(nullptr);
	ASSERT_EQ(pc.getVelocity(), 0);
}

TEST(PetrolCarTests, ShouldHaveNeutralGearAfterCreation)
{
	PetrolCar pc(nullptr);
	ASSERT_EQ(pc.getGear(), Gear::_N);
}

TEST(PetrolCarTests, 
	ShouldntChangeVelocityIfAccelerationIsEqualToZero)
{
	PetrolCar pc(nullptr);
	auto velocityBeforeAcceleration = pc.getVelocity();
	pc.accelerate(0);

	ASSERT_EQ(velocityBeforeAcceleration, pc.getVelocity());
}

TEST(PetrolCarTests, 
	ShouldIncreaseVelocityByGivenPositiveAccelerationValue)
{
	PetrolCar pc(nullptr);
	auto velocityBeforeAcceleration = pc.getVelocity();

	auto acceleration = 10;
	pc.accelerate(acceleration);

	ASSERT_NE(velocityBeforeAcceleration, pc.getVelocity());
	ASSERT_EQ(velocityBeforeAcceleration+acceleration, 
		pc.getVelocity());
}

TEST(PetrolCarTests, 
	ShouldThrowInvalidAccelerationValueExceptionIfAccelerationValueIsNegative)
{
	PetrolCar pc(nullptr);
	auto velocityBeforeAcceleration = pc.getVelocity();

	ASSERT_THROW(pc.accelerate(-1), InvalidAccelerationValue);
	ASSERT_EQ(velocityBeforeAcceleration, pc.getVelocity());
}

TEST(PetrolCarTests,
	ShouldntChangeGearIfGivenOneIsEqualToCurrent)
{
	PetrolCar pc(nullptr);
	auto gearBeforeChanging = pc.getGear();
	pc.changeGear(Gear::_N);

	ASSERT_EQ(gearBeforeChanging, pc.getGear());
}

TEST(PetrolCarTests, ShouldChangeGearToGiven)
{
	PetrolCar pc(nullptr);
	auto gear = Gear::_5;
	pc.changeGear(gear);

	ASSERT_EQ(gear, pc.getGear());
}

TEST(PetrolCarTests, 
	ShouldThrowInvalidGearExceptionWhileChangingFromPositiveGearToReverse)
{
	PetrolCar pc(nullptr);

	ASSERT_NO_THROW(pc.changeGear(Gear::_1));

	auto gearBeforeChanging = pc.getGear();

	ASSERT_THROW(pc.changeGear(Gear::_R), InvalidGear);
	ASSERT_EQ(gearBeforeChanging, pc.getGear());
}