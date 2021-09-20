#include "Car.hpp"
#include "PetrolEngine.hpp"
class PetrolCar : public Car {
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    virtual ~PetrolCar();
    void turnLeft() override;
    void turnRight() override;
    void brake() override;
    void accelerate(int speed) override;
    void refuel();

    const std::unique_ptr<PetrolEngine>& getPetrolEngine();

private:
    std::unique_ptr<PetrolEngine> petrolEngine_;
};
