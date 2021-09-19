cmake_minimum_required(VERSION 3.2)
project(cars)

# set build-in variables
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# set user variables
set(CAR_SOURCES ${CMAKE_SOURCE_DIR}/car)
set(ENGINE_SOURCES ${CMAKE_SOURCE_DIR}/engine)
set(EXCEPTION_SOURCES ${CMAKE_SOURCE_DIR}/exception)
set(TEST_SOURCES ${CMAKE_SOURCE_DIR}/test)

# headers path
include_directories(${CMAKE_SOURCE_DIR})

# locate googletest library
find_package(GTest REQUIRED)

# global gcc options
add_compile_options(-Wall -Wpedantic -Wextra) # -Werror

# sources library
set(SRC_LIST
    ${CAR_SOURCES}/Car.cpp
    ${CAR_SOURCES}/ElectricCar.cpp
    ${CAR_SOURCES}/HybridCar.cpp
    ${CAR_SOURCES}/PetrolCar.cpp
    ${ENGINE_SOURCES}/Engine.cpp
    ${ENGINE_SOURCES}/ElectricEngine.cpp
    ${ENGINE_SOURCES}/PetrolEngine.cpp
    ${EXCEPTION_SOURCES}/InvalidGear.cpp
    ${EXCEPTION_SOURCES}/InvalidSpeed.cpp
    ${EXCEPTION_SOURCES}/InvalidEngineChange.cpp
    ${EXCEPTION_SOURCES}/InvalidParameter.cpp
)
add_library(${PROJECT_NAME}-lib STATIC ${SRC_LIST})

# entry point
add_executable(${PROJECT_NAME} main.cpp)

# link entry point with sources
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

# test library
set(TEST_LIST
    ${TEST_SOURCES}/PetrolCar-ut.cpp
)
add_executable(${PROJECT_NAME}-ut ${TEST_LIST})
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib GTest::gtest_main)    

# enable ctest
enable_testing()
add_test(NAME cars-test COMMAND ${PROJECT_NAME}-ut)
