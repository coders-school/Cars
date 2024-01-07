cmake_minimum_required(VERSION 3.11.0)

project(Cars)  # Replace YourProjectName with the actual name of your project

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

set(SRC_LIST
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
    Car.cpp
    InvalidGear.cpp
)

add_library(${PROJECT_NAME}-lib STATIC ${SRC_LIST})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

enable_testing()

add_executable(${PROJECT_NAME}-ut tests.cpp)
target_link_libraries(${PROJECT_NAME}-ut PRIVATE ${PROJECT_NAME}-lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)
add_test(NAME runTests COMMAND ${PROJECT_NAME}-ut)
