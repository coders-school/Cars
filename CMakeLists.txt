cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Cars)

set(SRC_LIST
  Car.cpp
  ElectricCar.cpp
  ElectricEngine.cpp
  HybridCar.cpp
  # main.cpp
  PetrolCar.cpp
  PetrolEngine.cpp
)

# add_library(${PROJECT_NAME}-lib STATIC ${SRC_LIST})
# add_executable(${PROJECT_NAME} ${SRC_LIST})
# target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)
# target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

# unit tests

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# SET(TEST_LIST) {
#   ElectricCarTest.cpp
# }

add_executable(ElectricCar-gt test/ElectricCar-gt.cpp ${SRC_LIST})
target_link_libraries(ElectricCar-gt gtest_main)
target_link_directories(ElectricCar-gt PUBLIC ${CMAKE_SOURCE_DIR})
add_test(NAME ElectricCarTest COMMAND ElectricCar-gt)

add_executable(PetrolCar-gt test/PetrolCar-gt.cpp ${SRC_LIST})
target_link_libraries(PetrolCar-gt gtest_main)
target_link_directories(PetrolCar-gt PUBLIC ${CMAKE_SOURCE_DIR})
add_test(NAME PetrolCarTest COMMAND PetrolCar-gt)

add_executable(HybridCar-gt test/HybridCar-gt.cpp ${SRC_LIST})
target_link_libraries(HybridCar-gt gtest_main)
target_link_directories(HybridCar-gt PUBLIC ${CMAKE_SOURCE_DIR})
add_test(NAME HybridCarTest COMMAND HybridCar-gt)