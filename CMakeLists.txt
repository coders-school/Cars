cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Cars)

set(CAR_SOURCES ${CMAKE_SOURCE_DIR}/car)
set(ENGINE_SOURCES ${CMAKE_SOURCE_DIR}/engine)

set(SRC_LIST
    ${CAR_SOURCES}/Car.cpp
    ${CAR_SOURCES}/ElectricCar.cpp
    ${CAR_SOURCES}/HybridCar.cpp
    ${CAR_SOURCES}/PetrolCar.cpp
    ${ENGINE_SOURCES}/Engine.cpp
    ${ENGINE_SOURCES}/ElectricEngine.cpp
    ${ENGINE_SOURCES}/PetrolEngine.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
# target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)
target_compile_options(${PROJECT_NAME} PUBLIC -Wpedantic -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})
