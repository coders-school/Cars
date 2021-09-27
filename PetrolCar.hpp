#include "Car.hpp"
#include "PetrolEngine.hpp"
class PetrolCar : public Car {
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    virtual ~PetrolCar();

    void powerSuply() override;
    const std::unique_ptr<PetrolEngine>& getPetrolEngine();

    void changeEngine(int, float, int = 0, int = 0, int = 0) override;

private:
    std::unique_ptr<PetrolEngine> petrolEngine_;
    void refuel();
};
