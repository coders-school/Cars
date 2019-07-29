#include <iostream>
#include <sstream>

#include "Exceptions.hpp"
#include "Car.hpp"



void Car::turnRight()
{
    std::cout << __FUNCTION__ << std::endl; 
}

void Car::brake(int deaccelerate)
{

    std::ostringstream oos;
    if(deaccelerate < -m_MaxVelocity - m_CurrentVelocity || deaccelerate > 0) {
        oos << "Incorrect Deacceleration. Decceleration should be between: " << 0 << " and " << m_MaxVelocity;
        //throw IncorrectVelocity(oos.str());
    }

    if(m_CurrentVelocity + deaccelerate < 0 ) {
        m_CurrentVelocity = 0;
        oos << "You had stoped";
    }
    else {
        m_CurrentVelocity += deaccelerate;
        oos << "Your current speed is: " << m_CurrentVelocity;
    }
    std::cout << oos.str() << std::endl;
}

void Car::turnLeft()
{
    std::cout << __FUNCTION__ << std::endl; 
}

void Car::accelerate(int accelerate) // throw IncorrectVelocity if parameters are incorrect
{
    std::ostringstream oos;
    if(accelerate <= 0 || accelerate > m_MaxVelocity) {
        oos << "Incorrect acceleration. Acceleration should be between: " << 0 << " and " << m_MaxVelocity;
        throw new IncorrectVelocity(oos.str());
    }

    if(m_CurrentVelocity + accelerate > m_MaxVelocity) {
        m_CurrentVelocity = m_MaxVelocity;
        oos << "You can't go faster than: " << m_MaxVelocity;
    }
    else {
        m_CurrentVelocity += accelerate;
        oos << "Your current speed is: " << m_CurrentVelocity;
    }
    std::cout << oos.str() << std::endl;
}

int Car::getCurrentVelocity() const
{ 
    return m_CurrentVelocity;
}