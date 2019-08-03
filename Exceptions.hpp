#include <stdexcept>

class InvalidGear : public std::logic_error
{

    public:
        InvalidGear() : std::logic_error("Changing gear to 'R' is not allowed when velocity != 0")
                      {};
};
