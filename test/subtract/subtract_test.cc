#include <gtest/gtest.h>
#include <currency.hpp>

TEST(SubtractTest, SubtractInt) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.subtract(50);

    EXPECT_EQ(result.amount, 5000);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractNegativeInt) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.subtract(-50);

    EXPECT_EQ(result.amount, 15000);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractDouble) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.subtract(50.25);

    EXPECT_EQ(result.amount, 4975);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractNegativeDouble) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.subtract(-50.25);

    EXPECT_EQ(result.amount, 15025);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractDoubleWithMajorPrecision) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.subtract(50.575);

    EXPECT_EQ(result.amount, 4943);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractDoubleWithMinorPrecision) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.subtract(50.5);

    EXPECT_EQ(result.amount, 4950);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractIntString) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.subtract("R$50");

    EXPECT_EQ(result.amount, 5000);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractDoubleString) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.subtract("R$50.25");

    EXPECT_EQ(result.amount, 4975);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractNegativeString) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.subtract("-R$50");

    EXPECT_EQ(result.amount, 15000);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractCurrency) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(50, 2);

    Currency::Currency result = currency1.subtract(currency2);

    EXPECT_EQ(result.amount, 5000);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractNegativeCurrency) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(-50, 2);

    Currency::Currency result = currency1.subtract(currency2);

    EXPECT_EQ(result.amount, 15000);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractCurrencyMinorPrecision) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(50, 1);

    Currency::Currency result = currency1.subtract(currency2);

    EXPECT_EQ(result.amount, 5000);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractCurrencyMajorPrecision) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(50, 3);

    Currency::Currency result = currency1.subtract(currency2);

    EXPECT_EQ(result.amount, 5000);
    EXPECT_EQ(result.precision, 2);
}

