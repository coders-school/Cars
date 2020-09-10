cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 3.0)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg

project(Cars)

set(SRC_LIST
    Car.cpp
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    main.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
)

set(SRC_TEST
    ElectricCar-ut.cpp
    HybridCar-ut.cpp
    PetrolCar-ut.cpp
)

add_library(${PROJECT_NAME}-lib STATIC ${SRC_LIST})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)

add_executable(${PROJECT_NAME}-ut ${SRC_TEST})
target_link_libraries(${PROJECT_NAME}-ut PUBLIC ${PROJECT_NAME}-lib gtest_main)
add_test(NAME Cars_test COMMAND ${PROJECT_NAME}-ut)
