#include "Exceptions.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"

#include <iostream>
#include <vector>

#include "Tests.cpp"

/**
(3 punkty) Poprawcie interfejs, aby był jak najmniej podatny na niewłaściwe użycie (np. accelerate(-999))
(4 punktów) Napiszcie w dowolny sposób kilka testów do obecnej funkcjonalności, m.in. sprawdzających pole velocity. Nie musicie używać żadnego frameworka, jeśli nie znacie. Wystarczy funkcja assert().
(2 punkty) Utwórzcie wyjątek InvalidGear, który powinien być rzucony w momencie, gdy ktoś próbuje np. zmienić bieg z 5 na R. Powinien on dziedziczyć z jednego z wyjątków z biblioteki standardowej
 * 
 * 
 */

int main()
{
	Tests();

    Car* car = nullptr;

    ///// OPEL
    try
    {
        std::cout << std::endl << "OPEL" << std::endl;
        PetrolCar opel(new PetrolEngine(120, 1800, 6));
        car = &opel;
        
        car->accelerate(50);
        car->brake(-40);
        car->accelerate(100);
        car->fill();
    } catch(const IncorrectVelocity&  er) {
        std::cerr << er.what() << std::endl;
        
    } catch(const std::runtime_error&  er) {
        std::cerr << er.what() << std::endl;
    }

    ///// NISSAN
    try
    {
        std::cout << std::endl << "NISSAN" << std::endl;
        ElectricCar nissan(new ElectricEngine(130, 650));
        car = &nissan;
        
        car->fill();
        car->accelerate(80);
        car->turnLeft();
    } catch(const IncorrectVelocity&  er) {
        std::cerr << "error: " << er.what() << std::endl;
        
    } catch(const std::runtime_error&  er) {
        std::cerr << er.what() << std::endl;
    }

    ///// TOYOTA
    try
    {

        std::cout << std::endl << "TOYOTA" << std::endl;
        HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
        car= &toyota;
        
        car->accelerate(100);
        car->brake(-10);
        car->fill();
    } catch(const IncorrectVelocity&  er) {
        std::cerr << "error " << er.what() << std::endl;
        
    } catch(const std::runtime_error&  er) {
        std::cerr << er.what() << std::endl;
    }

	return 0;
}
