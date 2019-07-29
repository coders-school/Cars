
#include "Exceptions.hpp"
#include "PetrolEngine.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"

#include <cassert>
#include <iostream>

void PetrolEngine_Power_Test()
{


    PetrolEngine* engine = nullptr;
 /*    try
    {
        engine = new PetrolEngine(0, 2, 3);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
*/
    try
    {
        engine = new PetrolEngine(1, 2, 3);
        bool result = engine->getPower() == 1;
        assert(result && "value is Ok");
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
        
    }
    delete engine;

} 
/*
void PetrolEngine_Capacity_Test()
{
    PetrolEngine* engine = nullptr;
    try
    {
        engine = new PetrolEngine(20, 0, 3);
    }
    catch(const std::runtime_error& e)
    {
        assert(engine->getCapacity() >= 1);
        std::cerr << e.what() << '\n';
    }
    delete engine;

    try
    {
        engine = new PetrolEngine(20, 1, 3);
    }
    catch(const std::runtime_error& e)
    {
        assert(engine->getCapacity() >= 1);
        std::cerr << e.what() << '\n';
    }
    delete engine;
}   

void PetrolEngine_MaxGear_Test()
{
    PetrolEngine* engine = nullptr;
    try
    {
        engine = new PetrolEngine(20, 2, 0);
    }
    catch(const std::runtime_error& e)
    {
        assert(engine->getMaxGear() >= 1);
        std::cerr << e.what() << '\n';
    }
    delete engine;

    try
    {
        engine = new PetrolEngine(20, 2, 1);
    }
    catch(const std::runtime_error& e)
    {
        assert(engine->getMaxGear() >= 1);
        std::cerr << e.what() << '\n';
    }
    delete engine;
}   
    
    

void PetrolEngine_changeGear_Test()
{
    //PetrolEngine* engine = nullptr;
    //engine = new PetrolEngine(120, 1800, 6);
    //assert(engine->getCurrentGear() == 0);
    //engine->changeGear(-1);
    //assert(engine->getCurrentGear() == -1);
    //engine->changeGear(-3);
    //assert(engine->getCurrentGear() == -1);
    //engine->changeGear(3);
    //assert(engine->getCurrentGear() == 3);
    //engine->changeGear(7);
    //assert(engine->getCurrentGear() == 3);
}

void ElectricEngine_Test()
{
*/

 /*
 
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
*/
void PetrolCar_Test()
{

}

void Tests()
{
    PetrolEngine_Power_Test();
    //PetrolEngine_Capacity_Test();
    //PetrolEngine_MaxGear_Test();

    //PetrolEngine_changeGear_Test();
    //ElectricEngine_Test();
}