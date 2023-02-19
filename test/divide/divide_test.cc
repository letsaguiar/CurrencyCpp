#include <gtest/gtest.h>
#include "currency.hpp"

TEST(DivideTest, DivideInt) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.divide(100);

    EXPECT_EQ(result.amount, 100);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideNegativeInt) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.divide(-50);

    EXPECT_EQ(result.amount, -200);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideDouble) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.divide(100.50);

    EXPECT_EQ(result.amount, 99);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideNegativeDouble) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.divide(-50.25);

    EXPECT_EQ(result.amount, -199);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideDoubleWithMajorPrecision) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.divide(100.578);

    EXPECT_EQ(result.amount, 99);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideDoubleWithMinorPrecision) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.divide(100.5);

    EXPECT_EQ(result.amount, 99);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideIntString) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.divide("R$100");

    EXPECT_EQ(result.amount, 100);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideDoubleString) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.divide("R$100.50");

    EXPECT_EQ(result.amount, 99);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideNegativeString) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.divide("R$-50.25");

    EXPECT_EQ(result.amount, -199);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideCurrency) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(100, 3);

    Currency::Currency result = currency1.divide(currency2);

    EXPECT_EQ(result.amount, 100);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideNegativeCurrency) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(-50, 3);

    Currency::Currency result = currency1.divide(currency2);

    EXPECT_EQ(result.amount, -200);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideCurrencyWithMajorPrecision) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(100, 3);

    Currency::Currency result = currency1.divide(currency2);

    EXPECT_EQ(result.amount, 100);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideCurrencyWithMinorPrecision) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(100, 1);

    Currency::Currency result = currency1.divide(currency2);

    EXPECT_EQ(result.amount, 100);
    EXPECT_EQ(result.precision, 2);
}