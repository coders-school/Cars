#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
class HybridCar : public Car {
public:
    HybridCar(std::shared_ptr<PetrolEngine> petrolEng, std::shared_ptr<ElectricEngine> electricEng);
    virtual ~HybridCar();
    void turnLeft() override;
    void turnRight() override;
    void brake() override;
    void accelerate(int speed) override;
    void charge();
    void refuel();
 
 std::shared_ptr<ElectricEngine> getElectricEngine();
 std::shared_ptr<PetrolEngine> getPetrolEngine();   

private:
    std::shared_ptr<PetrolEngine> petrolEngine_;
    std::shared_ptr<ElectricEngine> electricEngine_;
};
