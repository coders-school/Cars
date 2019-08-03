#pragma once

#include <string>

enum class Gear
{
	_R = -1, 
	_N = 0,
	_1,
	_2,
	_3,
	_4,
	_5
};

namespace gear
{

inline std::string toString(Gear gear)
{
    switch(gear)
    {
	case Gear::_R:
		return "R";
	case Gear::_N:
		return "N";
	case Gear::_1:
		return "1";
	case Gear::_2:
		return "2";
	case Gear::_3:
		return "3";
	case Gear::_4:	
		return "4";
	case Gear::_5:
		return "5";
	default:
		return "Unknown gear";
    }
    return "Unknown gear";
}

}