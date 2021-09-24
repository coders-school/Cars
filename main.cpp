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
    PetrolCar opel(std::make_unique<PetrolEngine>(120_hp, 1800.0_ccm, 6));
    opel.accelerate(50_km_h);
    opel.brake();
    // try {
    //     opel.accelerate(-900_mile_h);
    // } catch (const std::logic_error& err) {
    //     std::cout << err.what() << '\n';
    // }
    opel.refuel();
    opel.changeGear(3);
    //opel.changeGear(-1);

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(130_hp, 650_Ah));
    nissan.charge();
    nissan.accelerate(80_mile_h);
    
    auto newEngine = std::make_unique<ElectricEngine>( 150_hp, 700_Ah);  // Changing an engine during driving is not safe
    //auto newEngine = std::make_unique<ElectricEngine>( Power::powerHp(150), ElectricCapacity::capacityAh(700));  // Changing an engine during driving is not safe
    std::cout << newEngine.get() << '\n';
    nissan.engineSwap(newEngine);
    std::cout << newEngine.get() << '\n';
    nissan.engineSwap(newEngine);
    std::cout << newEngine.get() << '\n';

    nissan.turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(80_hp, 1400.0_ccm, 5),
                     std::make_unique<ElectricEngine>(100_hp, 540_Ah));
    toyota.accelerate(100_km_h);
    toyota.brake();
    toyota.charge();
    toyota.refuel();

    try {
        toyota.changeGear(3);
        toyota.changeGear(-1);
    } catch (const InvalidGear& err) {
        std::cout << err.what() << '\n';
    }
    toyota.changeGear(0);
    try {
        toyota.changeGear(-1);
        toyota.changeGear(5);
    } catch (const InvalidGear& err) {
        std::cout << err.what() << '\n';
    }
}
