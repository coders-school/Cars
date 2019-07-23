cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Cars)

set(SRC_LIST
    Car.hpp
    Car.cpp
    ElectricCar.cpp
    ElectricCar.hpp
    ElectricEngine.cpp
    ElectricEngine.hpp
    HybridCar.cpp
    HybridCar.hpp
    main.cpp
    PetrolCar.cpp
    PetrolCar.hpp
    PetrolEngine.cpp
    PetrolEngine.hpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
add_compile_options(${PROJECT_NAME} -Wall -Werror -Wpedantic -Wextra)
