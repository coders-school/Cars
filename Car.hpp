#ifndef CAR_H
#define CAR_H

class Car
{
    int currentSpeed_ = 0;
	int maxSpeed_ = 200;

public:
    // Constructor
    Car() = default;

    // Destructor
    virtual ~Car() = default;

    void turnLeft();

    void turnRight();

    void brake(int Deaccelerate);

	// throw IncorrectVelocity if parameters are incorrect
    void accelerate(int speed);

    virtual void fill() = 0;

    int getCurrentSpeed() const;

	int getMaxSpeed() const;
};


#endif // !CAR_H