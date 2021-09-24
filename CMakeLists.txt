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

set(SRC_LIST
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    main.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
    Engine.cpp
    Car.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(tests-gt tests.cpp ${SRC_LIST})
target_link_libraries(tests-gt gtest_main)
enable_testing()
add_test(NAME tests_test COMMAND tests-gt)




