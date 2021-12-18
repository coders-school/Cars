#include <iostream>
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include "HybridCar.hpp"
#include "InvalidGear.hpp"
#include "PetrolCapacity.hpp"

int main() {
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(120_hp, 1800.0_ccm, ManualGear::g_6th));
    opel.accelerate(50_km_h);
    opel.brake();
    opel.refuel();
    opel.changeGear(ManualGear::g_3th);
    //opel.changeGear(ManualGear::reverse);

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(130_hp, 650_Ah));
    nissan.charge();
    nissan.accelerate(50_km_h);
    
    auto newEngine = std::make_unique<ElectricEngine>( 150_hp, 700_Ah);  // Changing an engine during driving is not safe
    //auto newEngine = std::make_unique<ElectricEngine>( Power::powerHp(150), ElectricCapacity::capacityAh(700));
    std::cout << newEngine.get() << '\n';
    nissan.engineSwap(newEngine);
    std::cout << newEngine.get() << '\n';
    nissan.engineSwap(newEngine);
    std::cout << newEngine.get() << '\n';

    nissan.turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(80_hp, 1400.0_ccm, ManualGear::g_5th),
                     std::make_unique<ElectricEngine>(100_hp, 540_Ah));
    toyota.accelerate(100_km_h);
    toyota.brake();
    toyota.charge();
    toyota.refuel();

    try {
        toyota.changeGear(ManualGear::g_3th);
        toyota.changeGear(ManualGear::reverse);
    } catch (const InvalidGear& err) {
        std::cout << err.what() << '\n';
    }
    toyota.changeGear(ManualGear::neutral);
    try {
        toyota.changeGear(ManualGear::reverse);
        toyota.changeGear(ManualGear::g_5th);
    } catch (const InvalidGear& err) {
        std::cout << err.what() << '\n';
    }
}