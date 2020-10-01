#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>
#include <memory>

int main()
{
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(Power{120}, Capacity{1800}, Gears{6}));
    opel.accelerate(Speed{50});
    opel.brake();

    //opel.accelerate(Speed{-900}); //now will not compile
    opel.refuel();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(Power{130}, BatteryCapacity{650}));
    nissan.charge();
    nissan.accelerate(Speed{80});
    //  now is private
    //  nissan.engine_ = new ElectricEngine(Power{150}, BatteryCapacity{700});  // Changing an engine during driving is not safe

    nissan.turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(Power{80}, Capacity{1400}, Gears{5}), std::make_unique<ElectricEngine>(Power{100}, BatteryCapacity{540}));

    //how to change gear in toyota now ;) ... wee need gearbox..
    toyota.accelerate(Speed{100});
    toyota.brake();
    toyota.charge();
    toyota.refuel();
}
