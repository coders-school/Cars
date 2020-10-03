#include "ICar.hpp"
#include "PetrolEngine.hpp"
#include <memory>

class PetrolCar : public ICar
{
public:
    PetrolCar(std::unique_ptr<IEngine> engine);
    ~PetrolCar();

    void turnLeft() const override;
    void turnRight() const override;
    void brake() const override;
    void accelerate(Speed speed) const override;
    void refuel();
    void start_engine() const override;
    void stop_engine() const override;
    void fill() const override;

private:
    std::unique_ptr<IEngine> engine_ = nullptr;
};

