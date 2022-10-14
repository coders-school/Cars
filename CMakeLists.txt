cmake_minimum_required(VERSION 3.2)
project(Cars)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_LIST
        ElectricCar.cpp
        ElectricEngine.cpp
        HybridCar.cpp
        PetrolCar.cpp
        PetrolEngine.cpp
        Car.cpp
        Engine.cpp
        CarBehaviors.cpp
        )

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_library(${PROJECT_NAME}-lib STATIC ${SRC_LIST})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME}-ut test.cpp)
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)
