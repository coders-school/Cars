#include "Car.hpp"
#include "ElectricEngine.hpp"

class ElectricCar : public Car {
public:
    ElectricCar(std::shared_ptr<ElectricEngine> engine);
    virtual ~ElectricCar();

    void turnLeft() override;
    void turnRight();
    void brake();
    void accelerate(int);
    void charge();

    std::shared_ptr<ElectricEngine> getEngine();

private:
    std::shared_ptr<ElectricEngine> engine_;
};
