cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Cars)

set(SRC_LIST
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    main.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
    Car.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SRC_LIST_TESTS
  Car.cpp
  PetrolEngine.cpp
  ElectricEngine.cpp
  PetrolCar.cpp
  ElectricCar.cpp
  HybridCar.cpp
  ElectricCar-ut.cpp
  PetrolCar-ut.cpp
  HybridCar-ut.cpp
)

add_executable(${PROJECT_NAME}-ut ${SRC_LIST_TESTS})
target_link_libraries(${PROJECT_NAME}-ut gtest_main)

enable_testing()
add_test(NAME ${PROJECT_NAME}-ut COMMAND ${PROJECT_NAME}-ut)