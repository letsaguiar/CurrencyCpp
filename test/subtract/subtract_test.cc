#include <gtest/gtest.h>
#include <currency.hpp>

TEST(SubtractTest, SubtractInt) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.subtract(50);

    EXPECT_EQ(result.amount, 5000);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractNegativeInt) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.subtract(-50);

    EXPECT_EQ(result.amount, 15000);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractDouble) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.subtract(50.25);

    EXPECT_EQ(result.amount, 4975);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractNegativeDouble) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.subtract(-50.25);

    EXPECT_EQ(result.amount, 15025);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractDoubleWithMajorPrecision) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.subtract(50.575);

    EXPECT_EQ(result.amount, 4943);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractDoubleWithMinorPrecision) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.subtract(50.5);

    EXPECT_EQ(result.amount, 4950);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractIntString) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.subtract("R$50");

    EXPECT_EQ(result.amount, 5000);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractDoubleString) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.subtract("R$50.25");

    EXPECT_EQ(result.amount, 4975);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractNegativeString) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.subtract("-R$50");

    EXPECT_EQ(result.amount, 15000);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractCurrency) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(50, 2);

    CurrencyCpp::Currency result = currency1.subtract(currency2);

    EXPECT_EQ(result.amount, 5000);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractNegativeCurrency) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(-50, 2);

    CurrencyCpp::Currency result = currency1.subtract(currency2);

    EXPECT_EQ(result.amount, 15000);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractCurrencyMinorPrecision) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(50, 1);

    CurrencyCpp::Currency result = currency1.subtract(currency2);

    EXPECT_EQ(result.amount, 5000);
    EXPECT_EQ(result.precision, 2);
}

TEST(SubtractTest, SubtractCurrencyMajorPrecision) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(50, 3);

    CurrencyCpp::Currency result = currency1.subtract(currency2);

    EXPECT_EQ(result.amount, 5000);
    EXPECT_EQ(result.precision, 2);
}

