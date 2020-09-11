#include <iostream>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main() {
    Car* car_ptr = nullptr;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(std::make_shared<PetrolEngine>(120, 1800, 6));
    car_ptr = &opel;

    car_ptr->accelerate(50);
    car_ptr->brake();
    car_ptr->accelerate(-900);
    car_ptr->restore();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_shared<ElectricEngine>(130, 650));
    car_ptr = &nissan;
    car_ptr->restore();
    car_ptr->accelerate(-999);
    car_ptr->accelerate(60);
    nissan.setElectricEngine(std::make_shared<ElectricEngine>(
        150, 700));  // Changing an engine during driving is not safe
    car_ptr->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_shared<PetrolEngine>(80, 1400, 5),
                     std::make_shared<ElectricEngine>(100, 540));
    car_ptr = &toyota;
    car_ptr->accelerate(100);
    car_ptr->brake();
    car_ptr->restore();
}
