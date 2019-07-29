
#include "Exceptions.hpp"
#include "PetrolEngine.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"

#include <cassert>
#include <iostream>

void PetrolEngine_Constructor_invalid_argument_Test()
{
    std::cout << "\tStart Test: PetrolEngine_Constructor_invalid_argument_Test" << std::endl;

    PetrolEngine* engine = nullptr;

	// Power
    try
    {
        engine = new PetrolEngine(0, 2.f, 3);
    }
    catch(const std::invalid_argument& e)
    {
		std::string expected = "Power can't be lower than 1";
		assert(!expected.compare(e.what()));
    }
	assert(!engine);

    if(engine) 
        delete engine;

	// Capacity
    try
    {
        engine = new PetrolEngine(20, 0, 3);
		
    }
    catch(const std::invalid_argument& e)
    {
		std::string expected = "Capacity can't be lower than 1";
		assert(!expected.compare(e.what()));
    }
	assert(!engine);

    if(engine)
        delete engine;

	// Gears
    try
    {
        engine = new PetrolEngine(20, 1.f, 0);
		
    }
    catch(const std::invalid_argument& e)
    {
		std::string expected = "Gears need to be grater than 1";
		assert(!expected.compare(e.what()));
    }
	assert(!engine);

    if(engine)
        delete engine;

    std::cout << "\tEnd Test: PetrolEngine_Constructor_invalid_argument_Test" << std::endl << std::endl;
} 

void PetrolEngine_Constructor_valid_argument_Test()
{
    std::cout << "\tStart Test: PetrolEngine_Constructor_valid_argument_Test" << std::endl;
    PetrolEngine* engine = nullptr;
    try
    {
        engine = new PetrolEngine(1, 1, 1);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }

    if(engine)
	{
		assert(engine->getPower() == 1);
		assert(engine->getCapacity() == 1);
		assert(engine->getMaxGear() == 1);
		assert(engine->getCurrentGear() == 0);
        delete engine;
    }
    std::cout << "\tEnd Test: PetrolEngine_Constructor_valid_argument_Test" << std::endl << std::endl;
}
    
void PetrolEngine_changeGear_Test()
{
    std::cout << "\tStart Test: PetrolEngine_changeGear_Test" << std::endl;

    PetrolEngine* engine = nullptr;
   
	try
	{
		engine = new PetrolEngine(120, 1800, 6);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}

	if (engine)
	{
		assert(engine->getCurrentGear() == 0);
		engine->changeGear(-1);
		assert(engine->getCurrentGear() == -1);
		engine->changeGear(3);
		assert(engine->getCurrentGear() == 3);

		try
		{
			engine->changeGear(7);
			
		}
		catch (const InvalidGear& e)
		{
			std::string expected = "This Care have gear -1, 0 ... to ";
			expected += std::to_string(engine->getMaxGear());
			assert(!expected.compare(e.what()));
		}
		assert(engine->getCurrentGear() == 3);

		try
		{
			engine->changeGear(-3);

		}
		catch (const InvalidGear& e)
		{
			std::string expected = "This Care have gear -1, 0 ... to ";
			expected += std::to_string(engine->getMaxGear());
			assert(!expected.compare(e.what()));
		}
		assert(engine->getCurrentGear() == 3);
	}

    std::cout << "\tEnd Test: PetrolEngine_valid_argument_Test" << std::endl << std::endl;
}

void ElectricEngine_Constructor_invalid_argument_Test()
{
	std::cout << "\tStart Test: ElectricEngine_Constructor_invalid_argument_Test" << std::endl;

	ElectricEngine* engine = nullptr;

	// Power
	try
	{
		engine = new ElectricEngine(0, 2);
	}
	catch (const std::invalid_argument& e)
	{
		std::string expected = "Power can't be lower than 1";
		assert(!expected.compare(e.what()));
	}
	assert(!engine);

	if (engine)
		delete engine;

	// Capacity
	try
	{
		engine = new ElectricEngine(1, 0);

	}
	catch (const std::invalid_argument& e)
	{
		std::string expected = "Capacity can't be lower than 1";
		assert(!expected.compare(e.what()));
	}
	assert(!engine);

	if (engine)
		delete engine;

	std::cout << "\tEnd Test: ElectricEngine_Constructor_invalid_argument_Test" << std::endl << std::endl;
	
}

void ElectricEngine_Constructor_valid_argument_Test()
{
	std::cout << "\tStart Test: ElectricEngine_Constructor_valid_argument_Test" << std::endl;

	ElectricEngine* engine = nullptr;
	try
	{
		engine = new ElectricEngine(1, 1);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}

	if (engine)
	{
		
		assert(engine->getElectricPower() == 1);
		assert(engine->getBatteryCapacity() == 1);
		delete engine;
	}
	std::cout << "\tEnd Test: ElectricEngine_Constructor_valid_argument_Test" << std::endl << std::endl;
}

void PetrolCar_Constructor_Test()
{
	std::cout << "\tStart Test: PetrolCar_Constructor_Test" << std::endl;

	PetrolCar* petrolCar;
	try
	{
		petrolCar = new PetrolCar(new PetrolEngine(120, 1800, 6));
		
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
	assert(petrolCar->GetPetrolEngine());
	if (petrolCar) {
		delete petrolCar;
	}

	std::cout << "\tEnd Test: PetrolCar_Constructor_Test" << std::endl << std::endl;
}

void PetrolCar_accelerate_invalid_Test()
{
	std::cout << "\tStart Test: PetrolCar_accelerate_invalid_Test" << std::endl;

	PetrolCar* petrolCar;
	petrolCar = new PetrolCar(new PetrolEngine(120, 1800, 6));
	try
	{
		petrolCar->accelerate(-1);
	}
	catch (const IncorrectVelocity& e)
	{
		std::string expected = "Acceleration can't be negative";
		assert(!expected.compare(e.what()));
	}
	assert(petrolCar->getCurrentSpeed() == 0);
	
	petrolCar->accelerate(10);
	try
	{
		petrolCar->accelerate(191);
	}
	catch (const IncorrectVelocity& e)
	{
		std::string expected = "Acceleration can't be grater than: 190";
		assert(!expected.compare(e.what()));
	}
	assert(petrolCar->getCurrentSpeed() == 10);

	if (petrolCar) {
		delete petrolCar;
	}

	std::cout << "\tEnd Test: PetrolCar_accelerate_invalid_Test" << std::endl << std::endl;
}

void PetrolCar_accelerate_valid_Test()
{
	std::cout << "\tStart Test: PetrolCar_accelerate_valid_Test" << std::endl;

	PetrolCar* petrolCar;
	petrolCar = new PetrolCar(new PetrolEngine(120, 1800, 6));
	try
	{
		petrolCar->accelerate(10);
		assert(petrolCar->getCurrentSpeed() == 10);
		petrolCar->accelerate(petrolCar->getMaxSpeed() - petrolCar->getCurrentSpeed());
		assert(petrolCar->getCurrentSpeed() == 200);
	}
	catch (const IncorrectVelocity& e)
	{
		std::cerr << e.what() << '\n';
	}


	if (petrolCar) {
		delete petrolCar;
	}

	std::cout << "\tEnd Test: PetrolCar_accelerate_valid_Test" << std::endl << std::endl;
}

void PetrolCar_deaccelerate_invalid_Test()
{
	std::cout << "\tStart Test: PetrolCar_deaccelerate_invalid_Test" << std::endl;

	PetrolCar* petrolCar;
	petrolCar = new PetrolCar(new PetrolEngine(120, 1800, 6));
	petrolCar->accelerate(150);
	
	try
	{
		petrolCar->brake(1);
	}
	catch (const IncorrectVelocity& e)
	{
		std::string expected = "Incorrect value. Decceleration speed need to be negative: ";
		assert(!expected.compare(e.what()));
	}
	assert(petrolCar->getCurrentSpeed() == 150);
	petrolCar->accelerate(10);

	try
	{
		petrolCar->brake( -(petrolCar->getCurrentSpeed() +1 ) );
	}
	catch (const IncorrectVelocity& e)
	{
		std::string expected = "Incorrect value. Decceleration should be between: 0 and -160";
		std::string ss = e.what();
		assert(!expected.compare(e.what()));
	}
	assert(petrolCar->getCurrentSpeed() == 160);

	if (petrolCar) {
		delete petrolCar;
	}

	std::cout << "\tEnd Test: PetrolCar_deaccelerate_invalid_Test" << std::endl << std::endl;
}

void PetrolCar_deaccelerate_valid_Test()
{
	std::cout << "\tStart Test: PetrolCar_deaccelerate_valid_Test" << std::endl;

	PetrolCar* petrolCar;
	petrolCar = new PetrolCar(new PetrolEngine(120, 1800, 6));
	petrolCar->accelerate(150);
	try
	{
		petrolCar->brake(-10);
		assert(petrolCar->getCurrentSpeed() == 140);
		petrolCar->brake( -petrolCar->getCurrentSpeed() );
		assert(petrolCar->getCurrentSpeed() == 0);
	}
	catch (const IncorrectVelocity& e)
	{
		std::cerr << e.what() << '\n';
	}

	if (petrolCar) {
		delete petrolCar;
	}

	std::cout << "\tEnd Test: PetrolCar_deaccelerate_valid_Test" << std::endl << std::endl;
}

void Tests()
{
    std::cout << "Tests started" << std::endl;

	//Petrol engine
    PetrolEngine_Constructor_invalid_argument_Test();
    PetrolEngine_Constructor_valid_argument_Test();
    PetrolEngine_changeGear_Test();

	//Electric engine
	ElectricEngine_Constructor_invalid_argument_Test();
	ElectricEngine_Constructor_valid_argument_Test();

	// Petrol Car
	PetrolCar_Constructor_Test();
	PetrolCar_accelerate_invalid_Test();
	PetrolCar_accelerate_valid_Test();

	PetrolCar_deaccelerate_invalid_Test();
	PetrolCar_deaccelerate_valid_Test();

    std::cout << "Tests ended" << std::endl;
}