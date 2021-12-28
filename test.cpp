#include <vector>
#include "InvalidGear.hpp"
#include "PetrolCar.hpp"
#include "gtest/gtest.h"

TEST(ExceptionTest, ThrowsInvalidGearException) {
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    auto testedGears = std::vector<int>{-2, 7};
    for (size_t i = 0; i < testedGears.size(); i++) {
        EXPECT_THROW({
            try {
                opel.changeGear(testedGears[i]);
                FAIL() << "ERROR: function changeGear() should throw an error\n";
            } catch (const InvalidGear& exception) {
                EXPECT_STREQ(exception.what(), "Invalid gear");
                throw;
            } catch (const std::logic_error& exception) {
                FAIL() << "ERROR: Was expecting InvalidGear exception: " << exception.what() << std::endl;
            } catch (...) {
                FAIL() << "ERROR: Unexpected exception thrown: " << std::current_exception << std::endl;
            }
        },
                     InvalidGear);
    }
}
