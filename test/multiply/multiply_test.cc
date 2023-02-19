#include <gtest/gtest.h>
#include "currency.hpp"

TEST(MultiplyTest, MultiplyInt) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.multiply(100);

    EXPECT_EQ(result.amount, 1000000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyNegativeInt) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.multiply(-50);

    EXPECT_EQ(result.amount, -500000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyDouble) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.multiply(100.50);

    EXPECT_EQ(result.amount, 1005000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyNegativeDouble) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.multiply(-50.25);

    EXPECT_EQ(result.amount, -502500);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyDoubleWithMajorPrecision) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.multiply(100.578);

    EXPECT_EQ(result.amount, 1005780);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyDoubleWithMinorPrecision) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.multiply(100.5);

    EXPECT_EQ(result.amount, 1005000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyIntString) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.multiply("R$100");

    EXPECT_EQ(result.amount, 1000000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyDoubleString) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.multiply("R$100.50");

    EXPECT_EQ(result.amount, 1005000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyNegativeString) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.multiply("-R$100.50");

    EXPECT_EQ(result.amount, -1005000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyCurrency) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(100, 2);

    Currency::Currency result = currency1.multiply(currency2);

    EXPECT_EQ(result.amount, 1000000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyNegativeCurrency) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(-100, 2);

    Currency::Currency result = currency1.multiply(currency2);

    EXPECT_EQ(result.amount, -1000000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyCurrencyWithMajorPrecision) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(100, 3);

    Currency::Currency result = currency1.multiply(currency2);

    EXPECT_EQ(result.amount, 1000000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyCurrencyWithMinorPrecision) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(100, 1);

    Currency::Currency result = currency1.multiply(currency2);

    EXPECT_EQ(result.amount, 1000000);
    EXPECT_EQ(result.precision, 2);
}