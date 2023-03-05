add_library(CurrencyCpp STATIC
    currency.hpp
    init/init.cpp
    add/add.cpp
    subtract/subtract.cpp
    multiply/multiply.cpp
    divide/divide.cpp
    helpers/helpers.cpp
    amount/amount.cpp
    precision/precision.cpp
    percentage/percentage.cpp
    equals_to/equals_to.cpp
    greater_than/greater_than.cpp
    less_than/less_than.cpp
    greater_than_or_equal/greater_than_or_equal.cpp
    less_than_or_equal/less_than_or_equal.cpp
    is/is.cpp
    to_unit/to_unit.cpp
)

target_include_directories(CurrencyCpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})