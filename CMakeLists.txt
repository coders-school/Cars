cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_COMPILER g++-10)

project(Cars)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SRC_LIST
    Car.cpp
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
    Car.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST} main.cpp)

#target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra)
#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME}-ut ${SRC_LIST} test.cpp)
target_link_libraries(${PROJECT_NAME}-ut gtest_main)

enable_testing()
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME})
