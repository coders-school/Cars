cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME Cars)
project(${PROJECT_NAME})

set(SRC_LIST
    Car.hpp
    Car.cpp
    ElectricCar.cpp
    ElectricCar.hpp
    ElectricEngine.cpp
    ElectricEngine.hpp
    Engine.hpp
    HybridCar.cpp
    HybridCar.hpp
    main.cpp
    PetrolCar.cpp
    PetrolCar.hpp
    PetrolEngine.cpp
    PetrolEngine.hpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror -Wpedantic -Wextra -Wconversion)

add_subdirectory(${PROJECT_SOURCE_DIR}/googletest)

enable_testing()

include_directories(
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
        ${gmock_SOURCE_DIR}/include
        ${gmock_SOURCE_DIR})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

file(GLOB LIB_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
list(REMOVE_ITEM LIB_FILES ${PROJECT_SOURCE_DIR}/main.cpp)

add_executable(runUnitTests ${TEST_SRC_FILES} ${LIB_FILES})

target_link_libraries(runUnitTests gtest gtest_main gmock gmock_main)

