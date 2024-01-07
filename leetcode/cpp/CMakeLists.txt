# Usage:
#   sudo cmake -S . -B build
#   sudo cmake --build build
#   cd build
#   ctest -V

cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add your source files
set(SOURCE_FILES
  easy_algorithms.h
  easy_algorithms.cpp
  medium_algorithms.h
  medium_algorithms.cpp

  gtest/gtest_test_template.h
  gtest/gtest_easy_algorithms.cpp
  gtest/gtest_medium_algorithms.cpp
)

add_executable(
  gtest_algorithms
  ${SOURCE_FILES}
)

target_link_libraries(
  gtest_algorithms
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(gtest_algorithms)