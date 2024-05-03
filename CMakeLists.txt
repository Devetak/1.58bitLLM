cmake_minimum_required(VERSION 3.10)
project(1.58bitLLM)
set(CMAKE_CXX_STANDARD 11)

# Include directory for header files
include_directories(include)

# Add a library with both add.cpp and core_utils.cpp
add_library(addlib src/add.cpp src/core_utils.cpp src/utils.cpp)

# Add executables for the test suites
add_executable(test_add tests/test_add.cpp)
add_executable(test_core tests/test_core_utils.cpp)

# Link the library with the test executables
target_link_libraries(test_add addlib)
target_link_libraries(test_core addlib)

# Enable testing functionality
enable_testing()

# Add tests
add_test(NAME TestAdd COMMAND test_add)
add_test(NAME TestCore COMMAND test_core)

