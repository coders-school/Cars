#include "CarExceptions.hpp"
#include "HybridCar.hpp"

#include "gtest/gtest.h"

class HybridCarTestable : public HybridCar
{
  public:
    HybridCarTestable(int maxSpeed,
                      int maxReverseSpeed,
                      const PetrolEngine& petrolEngine,
                      const ElectricEngine& electricEngine)
        : Car(maxSpeed, maxReverseSpeed)
        , HybridCar(150, -30, petrolEngine, electricEngine)
    { }

    int electricEnginePower() const
    {
        return ElectricCar::engine_.power();
    }

    int batteryCapacity() const
    {
        return ElectricCar::engine_.batteryCapacity();
    }

    int petrolEnginePower() const
    {
        return PetrolCar::engine_.power();
    }

    int petrolEngineCapacity() const
    {
        return PetrolCar::engine_.capacity();
    }
};

TEST(HybridCarRefillShould, throwOnAttemptToRefillWhenCarIsMoving)
{
    HybridCarTestable sut(180,
                          -25,
                          PetrolEngine(120, 1800, 6),
                          ElectricEngine(130, 650));
    sut.accelerate(30);

    EXPECT_EQ(sut.currentSpeed(), 30);
    EXPECT_THROW(sut.refill(), RefillError);

    HybridCarTestable sut2(180,
                           -25,
                           PetrolEngine(120, 1800, 6),
                           ElectricEngine(130, 650));
    sut2.accelerate(-10);

    EXPECT_EQ(sut2.currentSpeed(), -10);
    EXPECT_THROW(sut.refill(), RefillError);
}

TEST(HybridCarRefillShould, notThrowOnAttemptToRefillWhenCarIsStopped)
{
    HybridCarTestable sut(180,
                          -25,
                          PetrolEngine(120, 1800, 6),
                          ElectricEngine(130, 650));

    EXPECT_EQ(sut.currentSpeed(), 0);
    EXPECT_NO_THROW(sut.refill());
}

TEST(HybridCarReplaceEngineShould, throwOnCallWhenCarIsNotStopped)
{
    HybridCarTestable sut(180,
                          -25,
                          PetrolEngine(120, 1800, 6),
                          ElectricEngine(130, 650));
    sut.accelerate(30);

    PetrolEngine new_petrol_engine { 140, 2000, 6 };
    ElectricEngine new_electric_engine { 140, 700 };
    EXPECT_EQ(sut.currentSpeed(), 30);
    EXPECT_THROW(sut.replacePetrolEngine(std::move(new_petrol_engine)), ReplaceEngineError);
    EXPECT_THROW(sut.replaceElectricEngine(std::move(new_electric_engine)), ReplaceEngineError);

    HybridCarTestable sut2(180,
                           -25,
                           PetrolEngine(120, 1800, 6),
                           ElectricEngine(130, 650));
    sut2.accelerate(-10);

    PetrolEngine new_petrol_engine2 { 140, 2000, 6 };
    ElectricEngine new_electric_engine2 { 140, 700 };
    EXPECT_EQ(sut2.currentSpeed(), -10);
    EXPECT_THROW(sut2.replacePetrolEngine(std::move(new_petrol_engine2)), ReplaceEngineError);
    EXPECT_THROW(sut2.replaceElectricEngine(std::move(new_electric_engine2)), ReplaceEngineError);
}

TEST(HybridCarReplaceEngineShould, notThrowOnCallWhenCarIsStopped)
{
    HybridCarTestable sut(180,
                          -25,
                          PetrolEngine(120, 1800, 6),
                          ElectricEngine(130, 650));

    PetrolEngine new_petrol_engine { 140, 2000, 6 };
    ElectricEngine new_electric_engine { 140, 700 };

    EXPECT_EQ(sut.currentSpeed(), 0);
    EXPECT_NO_THROW(sut.replacePetrolEngine(std::move(new_petrol_engine)));
    EXPECT_NO_THROW(sut.replaceElectricEngine(std::move(new_electric_engine)));
}

TEST(HybridCarReplaceEngineShould, replaceEngineWhenCarIsStopped)
{
    HybridCarTestable sut(180,
                          -25,
                          PetrolEngine(120, 1800, 6),
                          ElectricEngine(130, 650));
    int old_petrol_power = sut.petrolEnginePower();
    int old_petrol_capacity = sut.petrolEngineCapacity();
    int old_electric_power = sut.electricEnginePower();
    int old_battery_capacity = sut.batteryCapacity();

    PetrolEngine new_petrol_engine { 140, 2000, 6 };
    ElectricEngine new_electric_engine { 145, 700 };
    EXPECT_EQ(sut.currentSpeed(), 0);
    sut.replacePetrolEngine(std::move(new_petrol_engine));
    sut.replaceElectricEngine(std::move(new_electric_engine));

    EXPECT_NE(old_petrol_power, sut.petrolEnginePower());
    EXPECT_NE(old_petrol_capacity, sut.petrolEngineCapacity());
    EXPECT_NE(old_electric_power, sut.electricEnginePower());
    EXPECT_NE(old_battery_capacity, sut.batteryCapacity());

    EXPECT_EQ(sut.petrolEnginePower(), 140);
    EXPECT_EQ(sut.petrolEngineCapacity(), 2000);
    EXPECT_EQ(sut.electricEnginePower(), 145);
    EXPECT_EQ(sut.batteryCapacity(), 700);
}

TEST(HybridCarReplaceEngineShould, notReplaceEngineWhenCarIsNotStopped)
{
    HybridCarTestable sut(180,
                          -25,
                          PetrolEngine(120, 1800, 6),
                          ElectricEngine(130, 650));
    sut.accelerate(30);
    int old_petrol_power = sut.petrolEnginePower();
    int old_petrol_capacity = sut.petrolEngineCapacity();
    int old_electric_power = sut.electricEnginePower();
    int old_battery_capacity = sut.batteryCapacity();

    PetrolEngine new_petrol_engine { 140, 2000, 6 };
    ElectricEngine new_electric_engine { 145, 700 };
    EXPECT_EQ(sut.currentSpeed(), 30);
    EXPECT_THROW(sut.replacePetrolEngine(std::move(new_petrol_engine)), ReplaceEngineError);
    EXPECT_THROW(sut.replaceElectricEngine(std::move(new_electric_engine)), ReplaceEngineError);
    EXPECT_EQ(old_petrol_power, sut.petrolEnginePower());
    EXPECT_EQ(old_petrol_capacity, sut.petrolEngineCapacity());
    EXPECT_EQ(old_electric_power, sut.electricEnginePower());
    EXPECT_EQ(old_battery_capacity, sut.batteryCapacity());

    HybridCarTestable sut2(180,
                           -25,
                           PetrolEngine(120, 1800, 6),
                           ElectricEngine(130, 650));
    sut2.accelerate(-10);
    int old_petrol_power2 = sut2.petrolEnginePower();
    int old_petrol_capacity2 = sut2.petrolEngineCapacity();
    int old_electric_power2 = sut2.electricEnginePower();
    int old_battery_capacity2 = sut2.batteryCapacity();

    PetrolEngine new_petrol_engine2 { 140, 2000, 6 };
    ElectricEngine new_electric_engine2 { 145, 700 };
    EXPECT_THROW(sut2.replacePetrolEngine(std::move(new_petrol_engine2)), ReplaceEngineError);
    EXPECT_THROW(sut2.replaceElectricEngine(std::move(new_electric_engine2)), ReplaceEngineError);
    EXPECT_EQ(old_petrol_power2, sut2.petrolEnginePower());
    EXPECT_EQ(old_petrol_capacity2, sut2.petrolEngineCapacity());
    EXPECT_EQ(old_electric_power2, sut2.electricEnginePower());
    EXPECT_EQ(old_battery_capacity2, sut2.batteryCapacity());
}
