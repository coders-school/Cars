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
set(testFile ../test/test.cpp ../test/catch_amalgamated.cpp)
enable_testing()
add_executable(${PROJECT_NAME} ${SRC_LIST} main.cpp)
add_executable(${PROJECT_NAME}-ut ${testFile} ${SRC_LIST})
add_test(NAME Tests-catch2 COMMAND ${PROJECT_NAME}-ut)

target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra)
target_compile_options(${PROJECT_NAME}-ut PUBLIC -Wall -Wpedantic -Wextra)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

