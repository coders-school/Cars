#include <iostream>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "Invalidgear.hpp"
#include "PetrolCar.hpp"

int main() {
    try {
        std::unique_ptr<ElectricCar> Ptr2 = std::make_unique<ElectricCar>(std::make_unique<ElectricEngine>(12, 180));

    } catch (std::invalid_argument const& a) {
        std::cout << a.what() << std::endl;
    }

    try {
        PetrolCar Audi(std::make_unique<PetrolEngine>(0, 4, 5));
    } catch (std::invalid_argument const& arg) {
        std::cout << arg.what() << std::endl;
    }

    try {
        HybridCar Audi(std::make_unique<PetrolEngine>(0, 4, 5), std::make_unique<ElectricEngine>(12, 180));

    } catch (std::invalid_argument const& arg) {
        std::cout << arg.what() << std::endl;
    }

    return 0;
}