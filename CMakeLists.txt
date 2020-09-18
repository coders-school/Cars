cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Cars)

include_directories(include)
include_directories(src)

set(SRC_LIST
    src/ElectricCar.cpp
    src/ElectricEngine.cpp
    src/HybridCar.cpp
    src/PetrolCar.cpp
    src/PetrolEngine.cpp
    src/Car.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})
