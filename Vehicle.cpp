#include "Vehicle.hpp"

Direction Vehicle::getNewDirection(Direction turn) {
    switch (turn) {
        case Direction::LEFT:
            if (currentDirection_ == Direction::LEFT) {
                return Direction::DOWN;
            } else if (currentDirection_ == Direction::UP) {
                return Direction::LEFT;
            } else if (currentDirection_ == Direction::RIGHT) {
                return Direction::UP;
            } else if (currentDirection_ == Direction::DOWN) {
                return Direction::RIGHT;
            }
            break;
        case Direction::RIGHT:
            if (currentDirection_ == Direction::LEFT) {
                return Direction::UP;
            } else if (currentDirection_ == Direction::UP) {
                return Direction::RIGHT;
            } else if (currentDirection_ == Direction::RIGHT) {
                return Direction::DOWN;
            } else if (currentDirection_ == Direction::DOWN) {
                return Direction::LEFT;
            }
            break;
        case Direction::DOWN:
        case Direction::UP:
        default:
            throw std::logic_error("you can only turn left or right!\n");
    }
    throw std::logic_error("other error in change direction!\n");
}

void Vehicle::turnLeft() {
    currentDirection_ = getNewDirection(Direction::LEFT);
}

void Vehicle::turnRight() {
    currentDirection_ = getNewDirection(Direction::RIGHT);
}

void Vehicle::changeSpeedTo(KMH speed) {
    currentSpeed_ = speed;
}
