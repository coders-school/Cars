cmake_minimum_required(VERSION 3.18)

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

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)


add_executable(${PROJECT_NAME} main.cpp ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME}-ut test.cpp ${SRC_LIST})
target_link_libraries(${PROJECT_NAME}-ut gtest_main)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra)


enable_testing ()
add_test (NAME test COMMAND ${PROJECT_NAME}-ut)
