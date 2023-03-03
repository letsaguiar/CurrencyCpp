#include <gtest/gtest.h>
#include "currency.hpp"

TEST(IsZero, True) {
    Currency::Currency currency(0, 2);

    EXPECT_TRUE(currency.isZero());
}

TEST(IsZero, False) {
    Currency::Currency currency(1, 2);

    EXPECT_FALSE(currency.isZero());
}

TEST(IsPositive, True) {
    Currency::Currency currency(1, 2);

    EXPECT_TRUE(currency.isPositive());
}

TEST(IsPositive, False) {
    Currency::Currency currency(0, 2);

    EXPECT_FALSE(currency.isPositive());
}

TEST(IsPositive, Zero) {
    Currency::Currency currency(0, 2);

    EXPECT_FALSE(currency.isPositive());
}

TEST(IsNegative, True) {
    Currency::Currency currency(-1, 2);

    EXPECT_TRUE(currency.isNegative());
}

TEST(IsNegative, False) {
    Currency::Currency currency(1, 2);

    EXPECT_FALSE(currency.isNegative());
}

TEST(IsNegative, Zero) {
    Currency::Currency currency(0, 2);

    EXPECT_FALSE(currency.isNegative());
}
