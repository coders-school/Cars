#ifndef CAR_H
#define CAR_H

class Car
{
    int m_CurrentVelocity = 0;
    int m_MaxVelocity = 200;

public:
    // Constructor
    Car() = default;

    // Destructor
    virtual ~Car() = default;

    void turnLeft();

    void turnRight();

    void brake(int Deaccelerate);

    void accelerate(int velocity); // throw Incorrect Balacity

    virtual void fill() = 0;

    int getCurrentVelocity() const;
};


#endif // !CAR_H