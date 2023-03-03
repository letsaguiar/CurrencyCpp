#include <gtest/gtest.h>
#include "currency.hpp"

TEST(IsZero, True) {
    CurrencyCpp::Currency currency(0, 2);

    EXPECT_TRUE(currency.isZero());
}

TEST(IsZero, False) {
    CurrencyCpp::Currency currency(1, 2);

    EXPECT_FALSE(currency.isZero());
}

TEST(IsPositive, True) {
    CurrencyCpp::Currency currency(1, 2);

    EXPECT_TRUE(currency.isPositive());
}

TEST(IsPositive, False) {
    CurrencyCpp::Currency currency(0, 2);

    EXPECT_FALSE(currency.isPositive());
}

TEST(IsPositive, Zero) {
    CurrencyCpp::Currency currency(0, 2);

    EXPECT_FALSE(currency.isPositive());
}

TEST(IsNegative, True) {
    CurrencyCpp::Currency currency(-1, 2);

    EXPECT_TRUE(currency.isNegative());
}

TEST(IsNegative, False) {
    CurrencyCpp::Currency currency(1, 2);

    EXPECT_FALSE(currency.isNegative());
}

TEST(IsNegative, Zero) {
    CurrencyCpp::Currency currency(0, 2);

    EXPECT_FALSE(currency.isNegative());
}
