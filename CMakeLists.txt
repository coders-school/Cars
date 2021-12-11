cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Cars)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(tests)

set(SRC_LIST
    Car.cpp
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
    Car.cpp
)

set(SRC_TESTS
    tests/PetrolEngine.ut.cpp)

set(FLAGS -Wall -Werror -Wpedantic -Wextra)

add_executable(${PROJECT_NAME} main.cpp ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PUBLIC ${FLAGS})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

enable_testing()

add_executable(${PROJECT_NAME}-ut ${SRC_LIST} ${SRC_TESTS})
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})
target_link_libraries(${PROJECT_NAME}-ut gtest_main)
add_test(NAME ${PROJECT_NAME}-tests COMMAND ${PROJECT_NAME}-ut)
