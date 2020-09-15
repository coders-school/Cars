#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>
#include <vector>

int main()
{   Car* car;
    std::vector<std::unique_ptr<ElectricEngine>> OldEngineShop;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    car = &opel;
    opel.getPetrolEngineData()->changeGear(4);
    car->accelerate(50);
    car->brake();
    try {
      opel.getPetrolEngineData()->changeGear(-1);
    } catch (WrongGearException &err1) {
      std::cerr << err1.what();
    }
    try {
      opel.getPetrolEngineData()->changeGear(3);
    } catch (WrongGearException &err1) {
      std::cerr << err1.what();
    }
    try {
      opel.getPetrolEngineData()->changeGear(-1);
    } catch (WrongGearException &err1) {
      std::cerr << err1.what();
    }
    try {
      opel.getPetrolEngineData()->changeGear(-2);
    } catch (WrongGearException &err1) {
      std::cerr << err1.what();
    }
    try {
      car->accelerate(-900);
    } catch (std::invalid_argument &err2) {
      std::cerr << err2.what();
    }

    car->restore();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));
    car = &nissan;
    car->restore();
    car->accelerate(80);

    try {
      OldEngineShop.push_back(nissan.pullOutElectricEngine());
    } catch (std::runtime_error &err) {
      std::cerr << err.what();
    }
    nissan.putInElectricEngine(std::make_unique<ElectricEngine>(150, 700));

    car->accelerate(0);
    try {
      OldEngineShop.push_back(nissan.pullOutElectricEngine());
    } catch (std::runtime_error &err) {
      std::cerr << err.what();
    }

    nissan.putInElectricEngine(std::make_unique<ElectricEngine>(150, 700));

    car->turnLeft();
    /**************************************
     Some fun with unique_ptr
    ****************************************/
    try {
      std::cout << "Nissan battery capacity: "
                << nissan.getElectricEngineData()->getBatteryCapacity() << '\n';
    } catch (std::runtime_error &err) {
      std::cerr << err.what();
    }

    car->accelerate(0);

    try {
      OldEngineShop.push_back(nissan.pullOutElectricEngine());
    } catch (std::runtime_error &err) {
      std::cerr << err.what();
    }

    try {
      if (OldEngineShop.size() != 0 && OldEngineShop.back()) {
        std::cout << "Battery capacity of pulled out engine is: "
                  << OldEngineShop.back()->getBatteryCapacity() << '\n';
      }
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }

    std::cout << "In shop we have got: " << OldEngineShop.size() << "engine(s)\n";

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(80, 1400, 5), std::make_unique<ElectricEngine>(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->restore();
    
}
