cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options("--coverage")

project(CurrencyCpp
    VERSION 1.0.0
    LANGUAGES CXX
    HOMEPAGE_URL "https://github.com/letsaguiar/CurrencyCpp"
)

# ---------- CurrencyCpp ----------
add_library(CurrencyCpp STATIC
    source/currency.hpp
    source/init/init.cpp
    source/add/add.cpp
    source/subtract/subtract.cpp
    source/multiply/multiply.cpp
    source/divide/divide.cpp
    source/helpers/helpers.cpp
    source/amount/amount.cpp
    source/precision/precision.cpp
    source/percentage/percentage.cpp
    source/equals_to/equals_to.cpp
    source/greater_than/greater_than.cpp
    source/less_than/less_than.cpp
    source/greater_than_or_equal/greater_than_or_equal.cpp
    source/less_than_or_equal/less_than_or_equal.cpp
    source/is/is.cpp
    source/to_unit/to_unit.cpp
)
target_include_directories(CurrencyCpp PUBLIC source)

set(MAIN_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MAIN_PROJECT ON)
endif()

if(${MAIN_PROJECT})
    # ---------- Google Test ----------
    include(FetchContent)
    FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    include(GoogleTest)

    # ---------- Enable Testing ----------
    enable_testing()

    # ---------- Unit Tests ----------
    add_executable(
        UnitTests

        test/main_test.cc
        test/init/init_test.cc
        test/add/add_test.cc
        test/subtract/subtract_test.cc
        test/multiply/multiply_test.cc
        test/divide/divide_test.cc
        test/amount/amount_test.cc
        test/precision/precision_test.cc
        test/percentage/percentage_test.cc
        test/equals_to/equals_to_test.cc
        test/greater_than/greater_than_test.cc
        test/less_than/less_than_test.cc
        test/greater_than_or_equal/greater_than_or_equal_test.cc
        test/less_than_or_equal/less_than_or_equal_test.cc
        test/is/is_test.cc
        test/to_unit/to_unit_test.cc
    )
    target_include_directories(UnitTests PUBLIC test)
    target_link_libraries(UnitTests CurrencyCpp)
    target_link_libraries(UnitTests gtest gtest_main)
    target_link_libraries(UnitTests gcov)
    gtest_discover_tests(UnitTests)

    # ---------- Coverage ----------
    add_custom_target(coverage
        COMMAND ctest

        COMMAND lcov -c -d . -o full_coverage.info

        COMMAND "lcov" 
            "-o" "coverage.info" 
            "-r" "full_coverage.info"
            "'/usr/include/*'"
            "'*/googletest/*'"
            "'*/test/*'"

        COMMAND genhtml coverage.info -o coverage
    )
endif()