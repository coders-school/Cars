cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Cars)
enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME}-ut)

set(SRC_LIST
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
    Car.cpp
    WrongGearException.cpp
)

add_executable(${PROJECT_NAME}-ut tests.cpp ${SRC_LIST})
add_executable(${PROJECT_NAME} main.cpp ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)
target_compile_options(${PROJECT_NAME}-ut PUBLIC -Wall -Werror -Wpedantic -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})
