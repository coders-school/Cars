#include <iostream>

#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"

void testPetrolCar(Car* car) {
    std::cout << std::endl << "# PETROL CAR TEST #" << std::endl;
    
    PetrolCar petrol(new PetrolEngine(120, 1800, 5));
    petrol.accelerateTo(50);
    try {
        petrol.accelerateTo(-900);
    } catch (const std::invalid_argument& ia) {
        std::cerr << " : " << ia.what() << std::endl;
    }
    petrol.brake();
    petrol.setEngine(new PetrolEngine(160, 2000, 6));
    petrol.restore();

    car = &petrol;
    car->accelerateTo(100);
    car->changeGear(4);
    car->changeGear(REVERSE);
    car->brake();
    car->changeGear(REVERSE);
    try {
        car->changeGear(9);
    } catch (const std::invalid_argument& ia) {
        std::cerr << " : " << ia.what() << std::endl;
    }
    car->restore();
}

void testElectricCar(Car* car) {
    std::cout << std::endl << "# ELECTRIC CAR TEST #" << std::endl;

    ElectricCar electric(new ElectricEngine(130, 650));
    electric.restore();
    electric.accelerateTo(80);
    electric.setEngine(new ElectricEngine(210, 1100));
    electric.turnLeft();

    car = &electric;
    car->changeGear(REVERSE);
    car->restore();
}

void testHybridCar(Car* car) {
    std::cout << std::endl << "# HYBRID CAR TEST #" << std::endl;

    HybridCar hybrid(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    hybrid.accelerateTo(100);
    hybrid.setEngine(new PetrolEngine(145, 190, 6), new ElectricEngine(130, 660));
    hybrid.brake();
    hybrid.restore();

    car = &hybrid;
    car->setEngine(new PetrolEngine(120, 160, 5), new ElectricEngine(100, 770));
    car->changeGear(9);
    car->restore();
}

int main() {
    Car* car = nullptr;
    testPetrolCar(car);
    testElectricCar(car);
    testHybridCar(car);

    return 0;
}
