#include <gtest/gtest.h>
#include "currency.hpp"

TEST(DivideTest, DivideInt) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.divide(100);

    EXPECT_EQ(result.amount, 100);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideNegativeInt) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.divide(-50);

    EXPECT_EQ(result.amount, -200);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideDouble) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.divide(100.50);

    EXPECT_EQ(result.amount, 99);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideNegativeDouble) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.divide(-50.25);

    EXPECT_EQ(result.amount, -199);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideDoubleWithMajorPrecision) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.divide(100.578);

    EXPECT_EQ(result.amount, 99);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideDoubleWithMinorPrecision) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.divide(100.5);

    EXPECT_EQ(result.amount, 99);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideIntString) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.divide("R$100");

    EXPECT_EQ(result.amount, 100);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideDoubleString) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.divide("R$100.50");

    EXPECT_EQ(result.amount, 99);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideNegativeString) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.divide("R$-50.25");

    EXPECT_EQ(result.amount, -199);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideCurrency) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(100, 3);

    CurrencyCpp::Currency result = currency1.divide(currency2);

    EXPECT_EQ(result.amount, 100);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideNegativeCurrency) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(-50, 3);

    CurrencyCpp::Currency result = currency1.divide(currency2);

    EXPECT_EQ(result.amount, -200);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideCurrencyWithMajorPrecision) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(100, 3);

    CurrencyCpp::Currency result = currency1.divide(currency2);

    EXPECT_EQ(result.amount, 100);
    EXPECT_EQ(result.precision, 2);
}

TEST(DivideTest, DivideCurrencyWithMinorPrecision) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(100, 1);

    CurrencyCpp::Currency result = currency1.divide(currency2);

    EXPECT_EQ(result.amount, 100);
    EXPECT_EQ(result.precision, 2);
}