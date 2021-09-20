cmake_minimum_required(VERSION 3.14)
project(cars)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

set(CAR_SOURCES ${CMAKE_SOURCE_DIR}/car)
set(ENGINE_SOURCES ${CMAKE_SOURCE_DIR}/engine)
set(EXCEPTION_SOURCES ${CMAKE_SOURCE_DIR}/exception)
set(TEST_SOURCES ${CMAKE_SOURCE_DIR}/test)

include_directories(${CMAKE_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/master.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_compile_options(-Wall -Werror -Wpedantic -Wextra)

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

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

set(TEST_LIST
    ${TEST_SOURCES}/PetrolCar-ut.cpp
    ${TEST_SOURCES}/ElectricCar-ut.cpp
    ${TEST_SOURCES}/HybridCar-ut.cpp
)
add_executable(${PROJECT_NAME}-ut ${TEST_LIST})
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib gtest_main)    

enable_testing()
add_test(NAME cars-test COMMAND ${PROJECT_NAME}-ut)
