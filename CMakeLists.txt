cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Cars)

set(SRC_LIST
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
    Car.cpp
)

set(TEST_SRC_LIST
    PetrolEngine.ut.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${SRC_LIST})
add_executable(${PROJECT_NAME}-ut catch_main.cpp ${SRC_LIST} ${TEST_SRC_LIST})

target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra)
target_compile_options(${PROJECT_NAME}-ut PUBLIC -Wall -Wpedantic -Wextra)

enable_testing()
add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-ut)
