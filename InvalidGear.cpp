#include"InvalidGear.hpp"

InvalidGear::InvalidGear(std::string msg) 
: logic_error(msg)
{
}

InvalidGear::~InvalidGear()
{
}
