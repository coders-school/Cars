cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
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

INCLUDE_DIRECTORIES(inc)
add_library(${PROJECT_NAME}-lib ${SRC_LIST})
add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)

set(CATCH_SRC_LIST
    test_catch/CarsTests
    )
add_executable(${PROJECT_NAME}-catch ${CATCH_SRC_LIST})
target_compile_options(${PROJECT_NAME}-catch PUBLIC -Wall -Werror -Wpedantic -Wextra)
target_link_libraries(${PROJECT_NAME}-catch ${PROJECT_NAME}-lib)

