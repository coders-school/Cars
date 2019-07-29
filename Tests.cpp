
#include "Exceptions.hpp"
#include "PetrolEngine.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"

#include <cassert>
#include <iostream>

void PetrolEngine_invalid_argument_Test()
{
    std::cout << "\tStart Test: PetrolEngine_invalid_argument_Test" << std::endl;

    PetrolEngine* engine = nullptr;
    try
    {
        engine = new PetrolEngine(0, 2, 3);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }


    if(engine) { 
        delete engine;
    }

    try
    {
        engine = new PetrolEngine(20, 0, 3);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }

    if(engine) { 
        delete engine;
    }

    try
    {
        engine = new PetrolEngine(20, 1, 0);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
        
    }
    if(engine) { 
        delete engine;
    }

    std::cout << "\tEnd Test: PetrolEngine_invalid_argument_Test" << std::endl << std::endl;
} 

void PetrolEngine_valid_argument_Test()
{
    std::cout << "\tStart Test: PetrolEngine_valid_argument_Test" << std::endl;
    PetrolEngine* engine = nullptr;
    try
    {
        engine = new PetrolEngine(1, 1, 1);

        assert(engine->getPower() == 1);

        assert(engine->getCapacity() == 1);

        assert(engine->getMaxGear() == 1);

        assert(engine->getCurrentGear() == 0);

    }
    catch(const std::invalid_argument& e)
    {

        std::cerr << e.what() << '\n';
    }

    if(engine) { 
        delete engine;
    }
    std::cout << "\tEnd Test: PetrolEngine_valid_argument_Test" << std::endl << std::endl;
}
    
void PetrolEngine_changeGear_Test()
{
    std::cout << "\tStart Test: PetrolEngine_changeGear_Test" << std::endl;

    PetrolEngine* engine = nullptr;
    engine = new PetrolEngine(120, 1800, 6);
    assert(engine->getCurrentGear() == 0);
    engine->changeGear(-1);
    assert(engine->getCurrentGear() == -1);
    engine->changeGear(3);
    assert(engine->getCurrentGear() == 3);
    

    try
    {
        engine->changeGear(7);
        assert(engine->getCurrentGear() == 3);
    }
    catch(const InvalidGear& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        engine->changeGear(-3);
        assert(engine->getCurrentGear() == 3);
    }
    catch(const InvalidGear& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\tEnd Test: PetrolEngine_valid_argument_Test" << std::endl << std::endl;
}

 /*
void ElectricEngine_Test()
{

 
    ElectricEngine* engine = nullptr;
    engine = new ElectricEngine(0, 0);
    assert(engine->getElectricPower() >= 1);
    assert(engine->getBatteryCapacity() >= 1);
    delete engine;


    engine = new ElectricEngine(-10, -10);
    assert(engine->getElectricPower() >= 1);
    assert(engine->getBatteryCapacity() >= 1);
    delete engine;
    

}

void PetrolCar_Test()
{

}
*/


void Tests()
{
    std::cout << "Tests started" << std::endl;

    PetrolEngine_invalid_argument_Test();
    PetrolEngine_valid_argument_Test();
    PetrolEngine_changeGear_Test();

    //PetrolEngine_changeGear_Test();
    //ElectricEngine_Test();

    std::cout << "Tests ended" << std::endl;
}