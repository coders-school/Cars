cmake_minimum_required(VERSION 3.11.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Cars)

set(SRC_LIST
    Car.cpp
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    main.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
    Car.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

enable_testing()

# test target
set(TEST_SRC_LIST
    Car.cpp
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
    tests/Car-UT.cpp
    tests/ElectricCar-UT.cpp
    tests/HybridCar-UT.cpp
    tests/PetrolCar-UT.cpp
    tests/PetrolEngine-UT.cpp
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

add_executable(${PROJECT_NAME}-tests ${TEST_SRC_LIST})

target_include_directories(${PROJECT_NAME}-tests
                           PRIVATE
                           ${CMAKE_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}-tests
                      gtest_main
)

target_compile_options(${PROJECT_NAME}-tests
                       PRIVATE
                       -Wall
                       -Wextra
                       -pedantic
)

# gtest_discover_tests(${PROJECT_NAME}-tests)
add_test(NAME Cars-tests COMMAND ${PROJECT_NAME}-tests)
