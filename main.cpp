#include "HybridCar.hpp"

#include <iostream>
#include <memory>

void printSeparator()
{
    std::cout << "------------------------------" << std::endl;
}

void testPetrolCar()
{
    std::cout << std::endl
              << "OPEL" << std::endl;
    auto opel = std::make_unique<PetrolCar>(150,
                                            -20,
                                            PetrolEngine(120, 1800, 6));
    opel->accelerate(50);
    opel->brake(40);
    opel->accelerate(-900);
    opel->accelerate(120);
    try {
        opel->replaceEngine(PetrolEngine(140, 2000, 6));
    }
    catch (const std::exception& except) {
        std::cout << except.what();
    }
    opel->brake();
    try {
        opel->replaceEngine(PetrolEngine(140, 2000, 6));
    }
    catch (const std::exception& except) {
        std::cout << except.what();
    }
    opel->accelerate(-15);
    opel->accelerate(-30);
    opel->brake(-10);
    opel->brake(30);
    opel->brake();
    opel->refill();
}

void testElectricCar()
{
    std::cout << std::endl
              << "NISSAN" << std::endl;
    auto nissan = std::make_unique<ElectricCar>(180,
                                                -25,
                                                ElectricEngine(130, 650));
    nissan->refill();
    nissan->accelerate(80);
    nissan->accelerate(-900);
    nissan->accelerate(120);
    try {
        nissan->replaceEngine(ElectricEngine(140, 700));
    }
    catch (const std::exception& except) {
        std::cout << except.what();
    }

    nissan->brake();
    try {
        nissan->replaceEngine(ElectricEngine(140, 700));
    }
    catch (const std::exception& except) {
        std::cout << except.what();
    }
    nissan->accelerate(-15);
    nissan->accelerate(-30);
    nissan->brake(-10);
    nissan->brake(30);
    nissan->brake();
}

void testHybridCar()
{
    std::cout << std::endl
              << "TOYOTA" << std::endl;
    auto toyota = std::make_unique<HybridCar>(150,
                                              -30,
                                              PetrolEngine(80, 1400, 5),
                                              ElectricEngine(100, 540));
    toyota->accelerate(100);
    toyota->brake();
    toyota->refill();
    toyota->accelerate(-900);
    toyota->accelerate(120);
    try {
        toyota->replaceElectricEngine(ElectricEngine(140, 700));
    }
    catch (const std::exception& except) {
        std::cout << except.what();
    }
    try {
        toyota->replacePetrolEngine(PetrolEngine(140, 2000, 6));
    }
    catch (const std::exception& except) {
        std::cout << except.what();
    }

    toyota->brake();
    try {
        toyota->replaceElectricEngine(ElectricEngine(140, 700));
    }
    catch (const std::exception& except) {
        std::cout << except.what();
    }
    try {
        toyota->replacePetrolEngine(PetrolEngine(140, 2000, 6));
    }
    catch (const std::exception& except) {
        std::cout << except.what();
    }
}

int main()
{
    testPetrolCar();
    printSeparator();

    testElectricCar();
    printSeparator();

    testHybridCar();
}
