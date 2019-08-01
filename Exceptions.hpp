#include <stdexcept>

class InvalidGear : public std::runtime_error
{

    public:
        InvalidGear() : std::runtime_error("You can not change the current gear to R. Slow down!")
                      {};
};
