#include "Car.hpp"
#include "PetrolEngine.hpp"
class PetrolCar : public Car {
public:
    PetrolCar(std::shared_ptr<PetrolEngine> engine);
    virtual ~PetrolCar();
    void turnLeft ()override;
    void turnRight ()override;
    void brake()override;
    void accelerate(int speed)override;
    void refuel();

std::shared_ptr<PetrolEngine>getEngine();

private:
    std::shared_ptr<PetrolEngine> engine_;
};
