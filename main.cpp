#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>

int main()
{   Car* car;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    car = &opel;
    car->accelerate(50);
    car->brake();
    
    try {
      car->accelerate(-900);
    } catch (std::invalid_argument& err) {
        std::cerr << err.what();
    }

    car->restore();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));
    car = &nissan;
    car->restore();
    car->accelerate(80);
    car->engine_ = std::make_unique<ElectricEngine>(150, 700);  // Changing an engine during driving is not safe
    car->turnLeft();

    /**************************************
     Tutaj się trochę pobawiłem unique_ptr ;)
    ****************************************/

    if(nissan.getElectricEngineData()){
    std::cout << "Nissan battery capacity: " << nissan.getElectricEngineData()->getBatteryCapacity() << '\n';
    }else std:: cout << "Ten samochod nie ma juz silnika!\n";

    std::unique_ptr<ElectricEngine> NissanPulledOutEngine = nissan.pullOutElectricEngine();
    std::cout << "Pojemnosc baterii wyciagnietego silnika to: " << NissanPulledOutEngine->getBatteryCapacity() << '\n';

    if(nissan.getElectricEngineData()){
    std::cout << "Nissan battery capacity: " << nissan.getElectricEngineData()->getBatteryCapacity() << '\n';
    }else std:: cout << "Ten samochod nie ma juz silnika!\n";

   

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(80, 1400, 5), std::make_unique<ElectricEngine>(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->restore();
    
}
