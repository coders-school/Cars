#include <stdexcept>

class InvalidGear : public std::logic_error
{

    public:
        InvalidGear() : std::logic_error("You can not change the current gear to R. Slow down!")
                      {};
};
