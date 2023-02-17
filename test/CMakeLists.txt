include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
    InitTest
    init/init_test.cc
    ../source/currency.hpp
    ../source/init/init.cpp
)

target_include_directories(
    InitTest
    PRIVATE ../source
)

target_link_libraries(
    InitTest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(
    InitTest
)