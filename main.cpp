#include <iostream>
#include "Car.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main() {
    Car* car = nullptr;
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    car = &opel;
    car->accelerate(50);
    car->brake();
    try {
        car->accelerate(-900);
    } catch (std::range_error& rerr) {
        std::cerr << rerr.what() << '\n';
    } catch (std::logic_error& err) {
        std::cerr << err.what() << '\n';
    }
    car->refill();
   

    // std::cout << std::endl
    //           << "NISSAN" << std::endl;
    // ElectricCar nissan(new ElectricEngine(130, 650));
    // car = &nissan;
    // car->refill();
    // car->accelerate(80);
    // // // nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    // // car->changeEngine(new ElectricEngine(150, 700));
    // car->turnLeft();

    // std::cout << std::endl
    //           << "TOYOTA" << std::endl;
    // HybridCar toyota(std::make_unique<PetrolEngine>(80, 1400, 5), new ElectricEngine(100, 540));
    // car = &toyota;
    // car->accelerate(100);
    // car->brake();
    // car->refill();

    try {
        PetrolEngine engine(100, 2000, 6);
        engine.changeGear(-1);
    } catch (std::logic_error& err) {
        std::cerr << err.what() << '\n';
    }
}
