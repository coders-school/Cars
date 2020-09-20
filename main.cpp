#include <iostream>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main() {
    Car* car = nullptr;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    car = &opel;
    car->accelerate(50);
    car->showSpeed();
    car->brake();
    try {
        car->accelerate(-900);
    } catch (const InvalidSpeed& ex) {
        std::cout << ex.what() << "\n";
    }
    car->showSpeed();
    car->restore();
    car->getInfoEngine();

    PetrolCar* car_p = dynamic_cast<PetrolCar*>(car);
    if (car_p) {
        car_p->getGear();
        car_p->changeEngine(std::make_unique<PetrolEngine>(140, 1700, 5));
        car_p->getInfoEngine();
    }
    try {
        opel.setGear(1);
        opel.getGear();
        opel.setGear(5);
        opel.getGear();
    } catch (const InvalidGear& ex) {
        std::cout << ex.what() << "\n";
    }
    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));

    nissan.charge();
    nissan.accelerate(80);
    nissan.showSpeed();
    try {
        // nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
        nissan.changeEngine(
            std::make_unique<ElectricEngine>(150, 700));  // Changing an engine during driving is not safe
        nissan.brake();
        nissan.showSpeed();
        nissan.changeEngine(
            std::make_unique<ElectricEngine>(150, 700));  // Changing an engine during driving is not safe
        nissan.turnLeft();
    } catch (const InvalidEngine& ex) {
        std::cout << ex.what() << "\n";
    }
    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(80, 1400, 5), std::make_unique<ElectricEngine>(100, 540));

    toyota.accelerate(100);
    toyota.brake();
    toyota.charge();
    toyota.refuel();

    car = &toyota;
    car->restore();
    car->getInfoEngine();

    car = &nissan;
    car_p = dynamic_cast<PetrolCar*>(car);

    if (car_p) {
        car_p->getGear();
    }
    car = &toyota;
    HybridCar* car_c = dynamic_cast<HybridCar*>(car);
    if (car_c) {
        car_c->changePetrolEngine(std::make_unique<PetrolEngine>(120, 1300, 5));
        car_c->changeElectricEngine(std::make_unique<ElectricEngine>(120, 1300));
        car_c->getInfoEngine();
    }
}