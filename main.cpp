#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "test.hpp"
#include <iostream>
#include <cassert>

void safeGearSet(PetrolCar& car, int gear)
{
    try
    {
        car.setGear(gear);
    }
    catch(std::logic_error &ex)
    {
       std::cout << ex.what() << std::endl;
    }
}


int main()
{
    PetrolCar fordMustang(new PetrolEngine(450,500,6));
     
        safeGearSet(fordMustang,1);
        safeGearSet(fordMustang,-1);
        safeGearSet(fordMustang,0);
        safeGearSet(fordMustang,-1);
        safeGearSet(fordMustang,1);
        safeGearSet(fordMustang,7);
        safeGearSet(fordMustang,3);

        accelerateTest(fordMustang);
        brakeTest(fordMustang);
    
    // ElectricCar nissan(new ElectricEngine(120, 4000));
    // nissan.changeElectricEngine(new ElectricEngine(130, 5000));
  
    // HybridCar rav4(new PetrolEngine(180, 1800,6), new ElectricEngine(120, 5000));
    // rav4.changePetrolEngine(new PetrolEngine(110, 1000, 6));
    // rav4.changeElectricEngine(new ElectricEngine(130, 5000));
    
    // rav4.accelerate(60);
    // rav4.changePetrolEngine(new PetrolEngine(180, 1800, 6));
    // rav4.changeElectricEngine(new ElectricEngine(140, 5500));
    
    // rav4.accelerate(200);
    // rav4.accelerate(50);
    // rav4.accelerate(50);
    // rav4.feed();
    // assert(250 == rav4.velocity);
    // assert(300 == rav4.velocity);

    // PetrolCar FordMustang(new PetrolEngine(450, 5000, 6));
    // FordMustang.accelerate(120);
    // FordMustang.accelerate(10);
    // FordMustang.accelerate(10);
    // FordMustang.feed();
    // FordMustang.feed();
 
    // Car* car = nullptr;
    // std::cout << std::endl << "OPEL" << std::endl;
    // PetrolCar opel(new PetrolEngine(120, 1800, 6));
    // car = &opel;
    // car->accelerate(50);
    // car->brake();
    // car->accelerate(-900);
    // car->feed();

    // std::cout << std::endl << "NISSAN" << std::endl;
    // ElectricCar nissan(new ElectricEngine(130, 650));
    // car = &nissan;
    // car->feed();
    // car->accelerate(80);
    // nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    // car->turnLeft();

    // std::cout << std::endl << "TOYOTA" << std::endl;
    // auto* pe = new PetrolEngine(80, 1400, 5);
    // HybridCar toyota(pe, new ElectricEngine(100, 540));
    // car = &toyota;
    // car->accelerate(100);
    // car->brake();
    // car->feed();
}
