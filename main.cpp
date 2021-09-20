<<<<<<< HEAD
#include "Car.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
=======
>>>>>>> transient
#include <iostream>
#include <memory>
#include <stdexcept>

#include "car/Car.hpp"
#include "car/PetrolCar.hpp"
#include "car/ElectricCar.hpp"
#include "car/HybridCar.hpp"
#include "engine/Engine.hpp"
#include "engine/PetrolEngine.hpp"
#include "engine/ElectricEngine.hpp"

int main()
{
    Car* car{};

    auto isuzu = new PetrolCar(std::make_unique<PetrolEngine>(120, 1800, 6));
    car = isuzu;
    car->accelerate(90);
    car->turnLeft();
    car->turnRight();
    car->brake();
    car->restore();
    try {
        isuzu->changeGear(-2);
    } catch (std::logic_error& le) {
        std::cout << le.what() << std::endl;
    }
    delete isuzu;
    std::cout << "-----------------------" << std::endl;

    auto nissan = new ElectricCar(std::make_unique<ElectricEngine>(130, 650));
    car = nissan;
    car->accelerate(90);
    car->turnLeft();
    car->turnRight();
    car->brake();
    car->restore();
    delete nissan;
    std::cout << "-----------------------" << std::endl;

    auto toyota = new HybridCar(std::make_unique<PetrolEngine>(90, 1400, 4),
                                std::make_unique<ElectricEngine>(80, 420));
    car = toyota;
    car->accelerate(90);
    car->turnLeft();
    car->turnRight();
    car->brake();
    car->restore();
    delete toyota;
    std::cout << "-----------------------" << std::endl;

    car = nullptr;
}
