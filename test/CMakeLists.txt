add_executable(
    UnitTest

    init/init_test.cc
    add/add_test.cc
    subtract/subtract_test.cc
    multiply/multiply_test.cc
    divide/divide_test.cc
    amount/amount_test.cc
    precision/precision_test.cc
    percentage/percentage_test.cc
    equals_to/equals_to_test.cc
    greater_than/greater_than_test.cc
    less_than/less_than_test.cc
    greater_than_or_equal/greater_than_or_equal_test.cc
    less_than_or_equal/less_than_or_equal_test.cc
    is/is_test.cc
    to_unit/to_unit_test.cc
)

target_include_directories(UnitTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})