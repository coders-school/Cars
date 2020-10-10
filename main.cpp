#include <iostream>

#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"

void testPetrolCar(Car* car) {
    std::cout << std::endl << "# PETROL CAR TEST #" << std::endl;
    
    PetrolCar petrol(std::make_shared<PetrolEngine>(120, 1800, 5));
    petrol.accelerateTo(50);
    try {
        petrol.accelerateTo(-900);
    } catch (const std::invalid_argument& ia) {
        std::cerr << " : " << ia.what() << std::endl;
    }
    petrol.brake();
    try {
        petrol.setEngine(std::make_shared<PetrolEngine>(160, 2000, 6));
        petrol.restore();
    } catch (const std::invalid_argument& ia) {
        std::cerr << " : " << ia.what() << std::endl;
    }
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
    try {
        car->restore();
    } catch (const std::invalid_argument& ia) {
        std::cerr << " : " << ia.what() << std::endl;
    }
}

void testElectricCar(Car* car) {
    std::cout << std::endl << "# ELECTRIC CAR TEST #" << std::endl;

    ElectricCar electric(std::make_shared<ElectricEngine>(130, 650));
    try {
        electric.restore();
    } catch (const std::invalid_argument& ia) {
        std::cerr << " : " << ia.what() << std::endl;
    }
    electric.accelerateTo(80);
    // electric.brake(); // to avoid memory leak
    try {
        electric.setEngine(std::make_shared<ElectricEngine>(210, 1100));
    } catch (const std::invalid_argument& ia) {
        std::cerr << " : " << ia.what() << std::endl;
    }
    electric.turnLeft();

    car = &electric;
    car->changeGear(REVERSE);
    try {
        car->restore();
    } catch (const std::invalid_argument& ia) {
        std::cerr << " : " << ia.what() << std::endl;
    }
}

void testHybridCar(Car* car) {
    std::cout << std::endl << "# HYBRID CAR TEST #" << std::endl;

    HybridCar hybrid(std::make_shared<PetrolEngine>(80, 1400, 5),
                     std::make_shared<ElectricEngine>(100, 540));
    hybrid.accelerateTo(100);
    try {
        hybrid.setEngine(std::make_shared<PetrolEngine>(145, 190, 6));
    } catch (const std::invalid_argument& ia) {
        std::cerr << " : " << ia.what() << std::endl;
    }
    hybrid.brake();
    try {
        hybrid.setEngine(std::make_shared<ElectricEngine>(130, 660));
    } catch (const std::invalid_argument& ia) {
        std::cerr << " : " << ia.what() << std::endl;
    }
    try {
        hybrid.restore();
    } catch (const std::invalid_argument& ia) {
        std::cerr << " : " << ia.what() << std::endl;
    }
    car = &hybrid;
    car->changeGear(9);
    try {
        car->restore();
    } catch (const std::invalid_argument& ia) {
        std::cerr << " : " << ia.what() << std::endl;
    }
}

int main() {
    Car* car = nullptr;

    testPetrolCar(car);
    testElectricCar(car);
    testHybridCar(car);

    return 0;
}
