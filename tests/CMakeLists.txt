project(Cars-tests
        LANGUAGES CXX)

set(TEST_SRC_LIST
    ../Car.cpp
    ../ElectricCar.cpp
    ../ElectricEngine.cpp
    ../HybridCar.cpp
    ../PetrolCar.cpp
    ../PetrolEngine.cpp
    Car-UT.cpp
    ElectricCar-UT.cpp
    HybridCar-UT.cpp
    PetrolCar-UT.cpp
    PetrolEngine-UT.cpp
)

# prepare Google Test
include(FetchContent)
FetchContent_Declare(
   googletest
   GIT_REPOSITORY https://github.com/google/googletest
   GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_executable(${PROJECT_NAME} ${TEST_SRC_LIST})

target_include_directories(${PROJECT_NAME}
                           PRIVATE
                           ${CMAKE_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}
                      gtest_main
)

target_compile_options(${PROJECT_NAME}
                       PRIVATE
                       -Wall
                       -Wextra
                       -pedantic
)

gtest_discover_tests(${PROJECT_NAME})
