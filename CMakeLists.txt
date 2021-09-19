cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Cars)

set(SRC_LIST
    Car.cpp
    Engine.cpp
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    main.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
    Car.cpp
)

# Release
set(FLAGS_RELEASE -Wall -Wpedantic -Wextra -Wconversion)
add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PUBLIC ${FLAGS_RELEASE})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

# Unit tests
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(PetrolCar-ut tests/PetrolCar-ut.cpp Car.cpp PetrolCar.cpp Engine.cpp PetrolEngine.cpp ElectricEngine.cpp)
target_link_libraries(PetrolCar-ut gtest_main)
target_include_directories(PetrolCar-ut PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(ElectricCar-ut tests/ElectricCar-ut.cpp Car.cpp ElectricCar.cpp Engine.cpp PetrolEngine.cpp ElectricEngine.cpp)
target_link_libraries(ElectricCar-ut gtest_main)
target_include_directories(ElectricCar-ut PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(HybridCar-ut tests/HybridCar-ut.cpp Car.cpp PetrolCar.cpp ElectricCar.cpp Engine.cpp PetrolEngine.cpp ElectricEngine.cpp HybridCar.cpp)
target_link_libraries(HybridCar-ut gtest_main)
target_include_directories(HybridCar-ut PUBLIC ${CMAKE_SOURCE_DIR})
