class CarsTests : public ::testing::Test
{
protected:
    PetrolCar opel{std::make_unique<PetrolEngine>(PetrolEngine(120, 1800, 6))};
    ElectricCar nissan{std::make_unique<ElectricEngine>(ElectricEngine(130, 650))};
    HybridCar toyota{std::make_unique<PetrolEngine>(PetrolEngine(80, 1400, 5)), std::make_unique<ElectricEngine>(ElectricEngine(100, 540))};
};