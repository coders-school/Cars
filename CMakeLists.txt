cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Cars)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        master
)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        devel
)

# After the following call, the CMake targets defined by googletest and
# Catch2 will be defined and available to the rest of the build

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest Catch2)

set(SRC_LIST
    Speed.cpp
    Power.cpp
    PetrolCapacity.cpp
    ElectricCapacity.cpp
    Car.cpp
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME}-ut Test.cpp ${SRC_LIST})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}-ut Catch2::Catch2WithMain)
# target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib gtest_main)

enable_testing()
add_test(NAME Tests-catch2 COMMAND ${PROJECT_NAME}-ut)