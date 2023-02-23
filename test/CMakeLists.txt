include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
    UnitTest

    init/init_test.cc
    add/add_test.cc
    subtract/subtract_test.cc
    multiply/multiply_test.cc
    divide/divide_test.cc
    amount/amount_test.cc

    ../source/currency.hpp
    ../source/init/init.cpp
    ../source/add/add.cpp
    ../source/subtract/subtract.cpp
    ../source/multiply/multiply.cpp
    ../source/divide/divide.cpp
    ../source/helpers/helpers.cpp
    ../source/amount/amount.cpp
)

target_include_directories(
    UnitTest
    PRIVATE ../source
)

target_link_libraries(
    UnitTest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(
    UnitTest
)