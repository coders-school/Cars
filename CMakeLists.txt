cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg

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
)

set(TESTS_LIST
    tests/PetrolCar.ut.cpp
    tests/PetrolEngine.ut.cpp
    )

add_library(${PROJECT_NAME}-lib STATIC ${SRC_LIST})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
set(FLAGS -Wall -Wextra -Werror -Wconversion -Wpedantic)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})

enable_testing()
add_executable(${PROJECT_NAME}-ut ${TESTS_LIST})
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib gtest_main)
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})

add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-ut)
