#include <gtest/gtest.h>
#include "currency.hpp"

TEST(MultiplyTest, MultiplyInt) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.multiply(100);

    EXPECT_EQ(result.amount, 1000000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyNegativeInt) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.multiply(-50);

    EXPECT_EQ(result.amount, -500000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyDouble) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.multiply(100.50);

    EXPECT_EQ(result.amount, 1005000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyNegativeDouble) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.multiply(-50.25);

    EXPECT_EQ(result.amount, -502500);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyDoubleWithMajorPrecision) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.multiply(100.578);

    EXPECT_EQ(result.amount, 1005700);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyDoubleWithMinorPrecision) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.multiply(100.5);

    EXPECT_EQ(result.amount, 1005000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyIntString) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.multiply("R$100");

    EXPECT_EQ(result.amount, 1000000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyDoubleString) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.multiply("R$100.50");

    EXPECT_EQ(result.amount, 1005000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyNegativeString) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.multiply("-R$100.50");

    EXPECT_EQ(result.amount, -1005000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyCurrency) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(100, 2);

    CurrencyCpp::Currency result = currency1.multiply(currency2);

    EXPECT_EQ(result.amount, 1000000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyNegativeCurrency) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(-100, 2);

    CurrencyCpp::Currency result = currency1.multiply(currency2);

    EXPECT_EQ(result.amount, -1000000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyCurrencyWithMajorPrecision) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(100, 3);

    CurrencyCpp::Currency result = currency1.multiply(currency2);

    EXPECT_EQ(result.amount, 1000000);
    EXPECT_EQ(result.precision, 2);
}

TEST(MultiplyTest, MultiplyCurrencyWithMinorPrecision) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(100, 1);

    CurrencyCpp::Currency result = currency1.multiply(currency2);

    EXPECT_EQ(result.amount, 1000000);
    EXPECT_EQ(result.precision, 2);
}