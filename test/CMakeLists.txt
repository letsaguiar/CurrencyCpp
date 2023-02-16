include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
    initialization_test
    initialization_test.cc
    ../source/currency.hpp
    ../source/initialization.cpp
)

target_include_directories(
    initialization_test
    PRIVATE ../source
)

target_link_libraries(
    initialization_test
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(
  initialization_test
)