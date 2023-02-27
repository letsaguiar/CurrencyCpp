#include <gtest/gtest.h>
#include "currency.hpp"

TEST(PercentageTest, IntPercentage) {
    Currency:: Currency currency(100, 2);
    Currency:: Currency result = currency.percentage(10);

    EXPECT_EQ(result.amount, 1000);
    EXPECT_EQ(result.precision, 2);
}

TEST(PercentageTest, DoublePercentage) {
    Currency:: Currency currency(100, 2);
    Currency:: Currency result = currency.percentage(25.75);

    EXPECT_EQ(result.amount, 2575);
    EXPECT_EQ(result.precision, 2);
}

TEST(PercentageTest, NegativePercentage) {
    Currency:: Currency currency(-100, 2);
    Currency:: Currency result = currency.percentage(10);

    EXPECT_EQ(result.amount, -1000);
    EXPECT_EQ(result.precision, 2);
}

TEST(PercentageTest, RequestNegativePercentage) {
    Currency:: Currency currency(100, 2);
    
    EXPECT_THROW(currency.percentage(-10), std::invalid_argument);
}