#include "Car.hpp"

void Car::turnLeft() { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight() { std::cout << __FUNCTION__ << std::endl; }
void Car::brake() { std::cout << __FUNCTION__ << std::endl; }
void Car::accelerate(int) { std::cout << __FUNCTION__ << std::endl; }
void Car::changeEngine(std::unique_ptr<ElectricEngine> engine)
{
    throw std::invalid_argument("This is not Electric Car");
}
void Car::changeEngine(std::unique_ptr<PetrolEngine> engine)
{
    throw std::invalid_argument("This is not Petrol Car");
}