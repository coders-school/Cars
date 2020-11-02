#include "CarExceptions.hpp"

InvalidGear::InvalidGear(std::string p_msg) : logic_error(p_msg) {}
