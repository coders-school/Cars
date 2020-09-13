cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

project(Cars)

set(SRC_LIST
    Car.cpp
    ElectricCar.cpp
    ElectricEngine.cpp
    Engine.cpp
    HybridCar.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
)
set(TEST_LIST
    ElectricCar-ut.cpp
    PetrolCar-ut.cpp  
    HybridCar-ut.cpp
)
add_executable(${PROJECT_NAME} ${SRC_LIST} main.cpp)
add_executable(${PROJECT_NAME}-ut ${TEST_LIST} ${SRC_LIST})
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})
