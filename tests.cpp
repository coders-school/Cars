#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include "HybridCar.hpp"
#include "catch.hpp"

// Electric Car is best implemented, so I will check only electric Car

SCENARIO("Checking if Electric functions works", "[ElectricCar]") {

  GIVEN("ElectricCar and Shop") {
    int power1 = 600;
    int power2 = 400;
    int batteryCapacity1 = 4000;
    int batteryCapacity2 = 3000;
    int stopSpeed = 0;
    int speed = 50;
    ElectricCar Tesla(
        std::make_unique<ElectricEngine>(power1, batteryCapacity1));
    std::vector<std::unique_ptr<ElectricEngine>> OldEngineShop;

    REQUIRE(Tesla.getElectricEngineData()->getBatteryCapacity() ==
            batteryCapacity1);
    REQUIRE(Tesla.getElectricEngineData()->getPower() >= power1);

    WHEN("car is moving") {

      Tesla.accelerate(speed);
      THEN("Cannot pull out engine") {
        REQUIRE_THROWS_AS(Tesla.pullOutElectricEngine(), std::runtime_error);
        REQUIRE(Tesla.getElectricEngineData()->getBatteryCapacity() ==
                batteryCapacity1);
        REQUIRE(Tesla.getElectricEngineData()->getPower() >= power1);
        REQUIRE(OldEngineShop.size() == 0);
      }
    }
    WHEN("car has stopped") {
      Tesla.accelerate(stopSpeed);
      THEN("returned engine unique ptr is not nullptr") {
        REQUIRE(Tesla.pullOutElectricEngine() != nullptr);
      }
    }

    WHEN("car has stopped and pulled out engine") {
      Tesla.accelerate(stopSpeed);
      Tesla.pullOutElectricEngine();
      THEN("unique_ptr is nullptr") {
        REQUIRE(Tesla.pullOutElectricEngine() == nullptr);
      }
    }
    WHEN("car has stopped and put in another engine") {
      Tesla.accelerate(stopSpeed);
      OldEngineShop.push_back(Tesla.pullOutElectricEngine());
      Tesla.putInElectricEngine(
          std::make_unique<ElectricEngine>(power2, batteryCapacity2));

      THEN("Check if there are new parameters") {
        REQUIRE(Tesla.getElectricEngineData()->getBatteryCapacity() ==
                batteryCapacity2);
        REQUIRE(Tesla.getElectricEngineData()->getPower() >= power2);
      }
    }
  }
}

SCENARIO("Checking if Petrol functions works", "[PetrolCar]") {

  GIVEN("PetrolCar and Shop") {
    int power1 = 600;
    int power2 = 400;
    int gear_number1 = 5;
    int gear_number2 = 6;
    int cubicCapacity1 = 1600;
    int cubicCapacity2 = 2000;
    int stopSpeed = 0;
    int speed = 50;
    PetrolCar Golf(
        std::make_unique<PetrolEngine>(power1, cubicCapacity1, gear_number1));
    std::vector<std::unique_ptr<PetrolEngine>> OldEngineShop;

    REQUIRE(Golf.getPetrolEngineData()->getCapacity() == cubicCapacity1);
    REQUIRE(Golf.getPetrolEngineData()->getPower() >= power1);

    WHEN("car is moving, and checking car data") {
      int ActualGear = 3;
      Golf.getPetrolEngineData()->changeGear(ActualGear);
      Golf.accelerate(speed);
      THEN("Cannot pull out engine") {
        REQUIRE_THROWS_AS(Golf.pullOutPetrolEngine(), std::runtime_error);
        REQUIRE(Golf.getPetrolEngineData()->getCapacity() == cubicCapacity1);
        REQUIRE(Golf.getPetrolEngineData()->getPower() >= power1);
        REQUIRE(OldEngineShop.size() == 0);
        REQUIRE(Golf.getPetrolEngineData()->currentGear_ == ActualGear);
      }
    }
    WHEN("car has stopped") {
      Golf.accelerate(stopSpeed);
      THEN("returned engine unique ptr is not nullptr") {
        REQUIRE(Golf.pullOutPetrolEngine() != nullptr);
      }
    }

    WHEN("car has stopped and pulled out engine") {
      Golf.accelerate(stopSpeed);
      Golf.pullOutPetrolEngine();
      THEN("unique_ptr is nullptr") {
        REQUIRE(Golf.pullOutPetrolEngine() == nullptr);
      }
    }
    WHEN("car has stopped and we put in another engine") {
      Golf.accelerate(stopSpeed);
      OldEngineShop.push_back(Golf.pullOutPetrolEngine());
      Golf.putInPetrolEngine(
          std::make_unique<PetrolEngine>(power2, cubicCapacity2, gear_number2));

      THEN("Check if there are new parameters") {
        REQUIRE(Golf.getPetrolEngineData()->getCapacity() == cubicCapacity2);
        REQUIRE(Golf.getPetrolEngineData()->getPower() >= power2);
        REQUIRE(Golf.getPetrolEngineData()->getPower() >= power2);
      }
    }
  }
}

SCENARIO("Checking if Hybrid functions works", "[HybridCar]") {

  GIVEN("HybridCar and Shop") {
    int power1 = 600;
    int power2 = 400;
    int gear_number1 = 5;
    int gear_number2 = 6;
    int cubicCapacity1 = 1600;
    int cubicCapacity2 = 2000;
    int batteryCapacity1 = 4000;
    int batteryCapacity2 = 3000;
    int stopSpeed = 0;
    int speed = 50;
    std::unique_ptr<PetrolEngine> PriusPetrolEngine =
        std::make_unique<PetrolEngine>(power1, cubicCapacity1, gear_number1);
    std::unique_ptr<ElectricEngine> PriusElectricEngine =
        std::make_unique<ElectricEngine>(power1, batteryCapacity1);
    HybridCar Prius(std::move(PriusPetrolEngine),
                    std::move(PriusElectricEngine));
    std::vector<std::unique_ptr<PetrolEngine>> OldPetrolEngineShop;
    std::vector<std::unique_ptr<ElectricEngine>> OldElectricEngineShop;

    REQUIRE(Prius.getPetrolEngineData()->getCapacity() == cubicCapacity1);
    REQUIRE(Prius.getPetrolEngineData()->getPower() >= power1);
    REQUIRE(Prius.getElectricEngineData()->getBatteryCapacity() ==
            batteryCapacity1);
    REQUIRE(Prius.getElectricEngineData()->getPower() >= power1);

    WHEN("car is moving, and checking car data") {
      int ActualGear = 3;
      Prius.getPetrolEngineData()->changeGear(ActualGear);
      Prius.accelerate(speed);
      THEN("Cannot pull out engines") {
        REQUIRE_THROWS_AS(Prius.pullOutPetrolEngine(), std::runtime_error);
        REQUIRE_THROWS_AS(Prius.pullOutElectricEngine(), std::runtime_error);
        REQUIRE(Prius.getPetrolEngineData()->getCapacity() == cubicCapacity1);
        REQUIRE(Prius.getPetrolEngineData()->getPower() >= power1);
        REQUIRE(OldPetrolEngineShop.size() == 0);
        REQUIRE(OldElectricEngineShop.size() == 0);
        REQUIRE(Prius.getPetrolEngineData()->currentGear_ == ActualGear);
      }
    }
    WHEN("car has stopped") {
      Prius.accelerate(stopSpeed);
      THEN("returned engines unique ptr are not nullptr") {
        REQUIRE(Prius.pullOutPetrolEngine() != nullptr);
        REQUIRE(Prius.pullOutElectricEngine() != nullptr);
      }
    }

    WHEN("car has stopped and pulled out both engines") {
      Prius.accelerate(stopSpeed);
      Prius.pullOutPetrolEngine();
      Prius.pullOutElectricEngine();
      THEN("unique_ptr are nullptr") {
        REQUIRE(Prius.pullOutPetrolEngine() == nullptr);
        REQUIRE(Prius.pullOutElectricEngine() == nullptr);
      }
    }
    WHEN("car has stopped and we put in another both engines") {
      Prius.accelerate(stopSpeed);

      OldPetrolEngineShop.push_back(Prius.pullOutPetrolEngine());
      Prius.putInPetrolEngine(
          std::make_unique<PetrolEngine>(power2, cubicCapacity2, gear_number2));

      OldElectricEngineShop.push_back(Prius.pullOutElectricEngine());
      Prius.putInElectricEngine(
          std::make_unique<ElectricEngine>(power2, batteryCapacity2));

      THEN("Check if there are new parameters") {
        REQUIRE(Prius.getPetrolEngineData()->getCapacity() == cubicCapacity2);
        REQUIRE(Prius.getPetrolEngineData()->getPower() >= power2);
        REQUIRE(Prius.getPetrolEngineData()->getPower() >= power2);
        REQUIRE(Prius.getElectricEngineData()->getBatteryCapacity() ==
                batteryCapacity2);
        REQUIRE(Prius.getElectricEngineData()->getPower() >= power2);
      }
    }
  }
}