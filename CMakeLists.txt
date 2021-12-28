cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

project(Cars)

set(SOURCES
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
    Car.cpp
)

set(FLAGS -Wall -Werror -Wpedantic -Wextra)

add_library(${PROJECT_NAME}-lib STATIC ${SOURCES})
target_compile_options(${PROJECT_NAME}-lib PUBLIC ${FLAGS})

add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PUBLIC ${FLAGS})
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME}-ut test.cpp)
target_compile_options(${PROJECT_NAME}-ut PUBLIC ${FLAGS})
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib gtest_main)
# enable_testing()
# add_test(NAME ${PROJECT_NAME}-ut COMMAND ${PROJECT_NAME}-ut)
