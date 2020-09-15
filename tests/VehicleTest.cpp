#include <gtest/gtest.h>
#include <unordered_map>

#include "PetrolCar.hpp"
#include "Vehicle.hpp"

class VehicleTests : public ::testing::Test {
   public:
    PetrolCar car{new PetrolEngine(HorsePower(100), CubicCentimetre(1000), Gear(4)), Litre(60)};
};

const std::unordered_map<Direction, std::string> directionToString {
    {Direction::LEFT, "LEFT"},
    {Direction::DOWN, "DOWN"},
    {Direction::UP, "UP"},
    {Direction::RIGHT, "RIGHT"}
};

std::ostream& operator<<(std::ostream& os, Direction dir) {
    os << directionToString.at(dir);
    return os;
}

TEST_F(VehicleTests, startingDirectionShouldBeRight) {
    auto expectedDirection = Direction::RIGHT;
    EXPECT_EQ(expectedDirection, car.getCurrentDirection());
}

TEST_F(VehicleTests, turnLeftShouldChangeDirection) {
    std::unordered_map<Direction, Direction> newDirectionAfterTurnLeft{
        {Direction::LEFT, Direction::DOWN},
        {Direction::UP, Direction::LEFT},
        {Direction::DOWN, Direction::RIGHT},
        {Direction::RIGHT, Direction::UP}};
    for (int i = 0; i < 100; ++i) {
        auto expectedDirection = newDirectionAfterTurnLeft.at(car.getCurrentDirection());
        car.turnLeft();
        EXPECT_EQ(expectedDirection, car.getCurrentDirection());
    }
}

TEST_F(VehicleTests, turnRightShouldChangeDirection) {
    std::unordered_map<Direction, Direction> newDirectionAfterTurnRight{
        {Direction::LEFT, Direction::UP},
        {Direction::UP, Direction::RIGHT},
        {Direction::DOWN, Direction::LEFT},
        {Direction::RIGHT, Direction::DOWN}};
    for (int i = 0; i < 100; ++i) {
        auto expectedDirection = newDirectionAfterTurnRight.at(car.getCurrentDirection());
        car.turnRight();
        EXPECT_EQ(expectedDirection, car.getCurrentDirection());
    }
}

TEST_F(VehicleTests, changeSpeedTo100ShouldChangeSpeedTo100) {
    KMH expectedSpeed = KMH(100);
    car.changeSpeedTo(KMH(100));
    auto actualSpeed = car.getCurrentSpeed();
    EXPECT_EQ(expectedSpeed.value_, actualSpeed.value_);
}

TEST_F(VehicleTests, startingSpeedShouldBe0) {
    auto expectedSpeed = KMH(0);
    EXPECT_EQ(expectedSpeed.value_, car.getCurrentSpeed().value_);
}

