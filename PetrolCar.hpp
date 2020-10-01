#include "ICar.hpp"
#include "PetrolEngine.hpp"
#include <memory>

class PetrolCar : public ICar
{
public:
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar();

    void turnLeft() const override;
    void turnRight() const override;
    void brake() const override;
    void accelerate(unsigned int speed) const override;
    void refuel();

private:
    std::unique_ptr<PetrolEngine> engine_ = nullptr;
};

