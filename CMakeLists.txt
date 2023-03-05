cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)

project(Currency)
enable_testing()

add_subdirectory(source)
add_subdirectory(test)

# ----- Testing -----
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(UnitTest CurrencyCpp)
target_link_libraries(UnitTest gtest_main)
# ----- Testing -----