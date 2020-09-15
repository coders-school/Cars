#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include "HybridCar.hpp"
#include "catch.hpp"
//#include "WrongGearException.hpp"

// Electric Car is best implemented, so I will check only electric Car

SCENARIO("Checking if Electric functions works", "[ElectricCar]") {

  GIVEN("ElectricCar, car raw_ptr and Shop") {
    ElectricCar Tesla(std::make_unique<ElectricEngine>(600, 4000));
    std::vector<std::unique_ptr<ElectricEngine>> OldEngineShop;

    REQUIRE(Tesla.getElectricEngineData()->getBatteryCapacity() == 4000);
    REQUIRE(Tesla.getElectricEngineData()->getPower() >= 600);

    WHEN("car is moving") {
      Tesla.accelerate(50);

      THEN("Cannot pull out engine") {
        REQUIRE_THROWS_AS(Tesla.pullOutElectricEngine(), std::runtime_error);
        REQUIRE(Tesla.getElectricEngineData()->getBatteryCapacity() == 4000);
        REQUIRE(Tesla.getElectricEngineData()->getPower() >= 600);
        REQUIRE(OldEngineShop.size() == 0);
      }
    }
    WHEN("car has stopped") {
      Tesla.accelerate(0);
      THEN("returned engine unique ptr is not nullptr") {
        REQUIRE(Tesla.pullOutElectricEngine() != nullptr);
      }
    }

    WHEN("car has stopped and pulled out engine") {
      Tesla.accelerate(0);
      Tesla.pullOutElectricEngine();
      THEN("unique_ptr is nullptr") {
        REQUIRE(Tesla.pullOutElectricEngine() == nullptr);
      }
    }
    WHEN("car has stopped and put in another engine") {
      Tesla.accelerate(0);
      OldEngineShop.push_back(Tesla.pullOutElectricEngine());
      Tesla.putInElectricEngine(std::make_unique<ElectricEngine>(400, 3000));

      THEN("Check if there are new parameters") {
        REQUIRE(Tesla.getElectricEngineData()->getBatteryCapacity() == 3000);
        REQUIRE(Tesla.getElectricEngineData()->getPower() >= 400);
      }
    }
  }
}
