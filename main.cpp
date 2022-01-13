#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>

int main()
{
    {
        std::cout << "\tPetrol ************************************************************\n";
        PetrolCar opel(new PetrolEngine(120, 1800, 6));
        std::cout << "Show opel: " << opel << '\n';
        PetrolCar bmw(new PetrolEngine(120, 1800, 6));

        PetrolCar mercedes = bmw;
        opel = bmw;

        PetrolCar fiat = std::move(bmw);

        opel = std::move(mercedes);
    }

    {
        std::cout << "\tElectric ************************************************************\n";
        ElectricCar tesla(new ElectricEngine(800, 100'000));
        std::cout << "Show tesla: " << tesla << '\n';
        ElectricCar kia(new ElectricEngine(300, 150'000));

        ElectricCar toyota = tesla;
        toyota = kia;

        ElectricCar honda(std::move(tesla));
        honda = std::move(kia);
    }
    std::cout << "\tHybrid ************************************************************\n";
    HybridCar tesla2(new PetrolEngine(120, 1800, 6), new ElectricEngine(800, 100'000));
    std::cout << "Show tesla2: " << tesla2 << '\n';
    HybridCar kia2(new PetrolEngine(120, 1800, 6), new ElectricEngine(300, 150'000));

    HybridCar toyota2 = tesla2;
    toyota2 = kia2;

    HybridCar honda2(std::move(tesla2));
    honda2 = std::move(kia2);
    
    // opel.accelerate(50);
    // opel.brake();
    // opel.accelerate(-900);
    // opel.refuel();

    // std::cout << std::endl << "NISSAN" << std::endl;
    // ElectricCar nissan(new ElectricEngine(130, 650));
    // nissan.charge();
    // nissan.accelerate(80);
    // nissan.setEngine(new ElectricEngine(150, 700));  // Changing an engine during driving is not safe
    // nissan.turnLeft();

    // std::cout << std::endl << "TOYOTA" << std::endl;
    // HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    // toyota.accelerate(100);
    // toyota.brake();
    // toyota.charge();
    // toyota.refuel();
}
