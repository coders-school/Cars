#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Car.hpp"
#include "../ElectricCar.hpp"


SCENARIO("Cars", "velocityTests")
{
    GIVEN("Cars, accelerate by value")
    {
        Car* testCar {nullptr};
        ElectricCar test(new ElectricEngine(100, 500));
        testCar = &test;
        int valueAccelerate {100};
        {
            WHEN("accelerate() is called")
            {
                testCar->accelerate(valueAccelerate);

                THEN("The velocity is valueAccelerate")
                {
                    CHECK(testCar->get_speed() == valueAccelerate);
                }
            }
        }
    }
    GIVEN("Cars, breake by value")
    {
        Car* testCar {nullptr};
        ElectricCar test(new ElectricEngine(100, 500));
        testCar = &test;
        int valueAccelerate {120};
        int valueBrake {100};
        {
            WHEN("accelerate() and brake() is called")
            {
                testCar->accelerate(valueAccelerate);
                testCar->brake(valueBrake);

                THEN("The velocity is valueAccelerate - valueBrake")
                {
                    CHECK(testCar->get_speed() == valueAccelerate - valueBrake);
                }
            }
        }
    }
    GIVEN("Cars, breake by value")
    {
        Car* testCar {nullptr};
        ElectricCar test(new ElectricEngine(100, 500));
        testCar = &test;
        int valueSetSpeed {100};
        int valueAccelerate {50};
        int valueBrake {150};
        {
            WHEN("accelerate() and brake() is called")
            {
                testCar->set_speed(valueSetSpeed);
                testCar->accelerate(valueAccelerate);
                testCar->brake(valueBrake);

                THEN("The velocity is valueSetSpeed + valueAccelerate - valueBrake")
                {
                    CHECK(testCar->get_speed() == valueSetSpeed + valueAccelerate - valueBrake);
                }
            }
        }
    }
}
