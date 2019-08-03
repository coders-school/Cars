#include <stdexcept>
#include <string>

class InvalidGear : public std::logic_error
{
public:
	InvalidGear()
	: std::logic_error(
		"Changing gear to 'R' is not allowed when velocity != 0")
    {
    }
};

class InvalidAccelerationValue : public std::invalid_argument
{
public:
	InvalidAccelerationValue(std::string invalidAccelerationValue)
	: std::invalid_argument(
		std::string("Acceleration value shouldn't be < 0, given: ")
		+ invalidAccelerationValue)
	{
	}
};