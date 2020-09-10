#include "Vehicle.hpp"

Vehicle::Vehicle(Engine* engine) : engine_(engine) {
}

Vehicle::~Vehicle() {
    delete engine_;
}
