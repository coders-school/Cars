#include "ICar.hpp"
#include "PetrolEngine.hpp"

class PetrolCar : public ICar
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();

    void turnLeft() const override;
    void turnRight() const override;
    void brake() const override;
    void accelerate(int speed) const override;
    void refuel();

    PetrolEngine* engine_;
};

