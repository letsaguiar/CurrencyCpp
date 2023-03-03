#include <gtest/gtest.h>
#include <currency.hpp>

TEST(AddTest, AddInt) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.add(100);

    EXPECT_EQ(result.amount, 20000);
    EXPECT_EQ(result.precision, 2);
}


TEST(AddTest, AddNegativeInt) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.add(-50);

    EXPECT_EQ(result.amount, 5000);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddDouble) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.add(100.50);

    EXPECT_EQ(result.amount, 20050);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddNegativeDouble) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.add(-50.25);

    EXPECT_EQ(result.amount, 4975);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddDoubleWithMajorPrecision) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.add(100.578);

    EXPECT_EQ(result.amount, 20057);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddDoubleWithMinorPrecision) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.add(100.5);

    EXPECT_EQ(result.amount, 20050);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddIntString) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.add("R$100");

    EXPECT_EQ(result.amount, 20000);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddDoubleString) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.add("R$100.50");

    EXPECT_EQ(result.amount, 20050);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddNegativeString) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency result = currency.add("-R$50.25");

    EXPECT_EQ(result.amount, 4975);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddCurrency) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(100, 2);

    CurrencyCpp::Currency result = currency1.add(currency2);

    EXPECT_EQ(result.amount, 20000);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddCurrencyMajorPrecision) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(100, 3);

    CurrencyCpp::Currency result = currency1.add(currency2);

    EXPECT_EQ(result.amount, 20000);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddCurrencyMinorPrecision) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(100, 1);

    CurrencyCpp::Currency result = currency1.add(currency2);

    EXPECT_EQ(result.amount, 20000);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddCurrencyNegative) {
    CurrencyCpp::Currency currency1(100, 2);
    CurrencyCpp::Currency currency2(-50, 2);

    CurrencyCpp::Currency result = currency1.add(currency2);

    EXPECT_EQ(result.amount, 5000);
    EXPECT_EQ(result.precision, 2);
}
