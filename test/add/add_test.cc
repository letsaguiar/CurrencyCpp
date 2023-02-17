#include <gtest/gtest.h>
#include <currency.hpp>

TEST(AddTest, AddInt) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.add(100);

    EXPECT_EQ(result.amount, 20000);
    EXPECT_EQ(result.precision, 2);
}


TEST(AddTest, AddNegativeInt) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.add(-50);

    EXPECT_EQ(result.amount, 5000);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddDouble) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.add(100.50);

    EXPECT_EQ(result.amount, 20050);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddNegativeDouble) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.add(-50.25);

    EXPECT_EQ(result.amount, 4975);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddDoubleWithMajorPrecision) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.add(100.578);

    EXPECT_EQ(result.amount, 20057);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddDoubleWithMinorPrecision) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.add(100.5);

    EXPECT_EQ(result.amount, 20050);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddIntString) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.add("R$100");

    EXPECT_EQ(result.amount, 20000);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddDoubleString) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.add("R$100.50");

    EXPECT_EQ(result.amount, 20050);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddNegativeString) {
    Currency::Currency currency(100, 2);
    Currency::Currency result = currency.add("-R$50.25");

    EXPECT_EQ(result.amount, 4975);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddCurrency) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(100, 2);

    Currency::Currency result = currency1.add(currency2);

    EXPECT_EQ(result.amount, 20000);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddCurrencyMajorPrecision) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(100, 3);

    Currency::Currency result = currency1.add(currency2);

    EXPECT_EQ(result.amount, 20000);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddCurrencyMinorPrecision) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(100, 1);

    Currency::Currency result = currency1.add(currency2);

    EXPECT_EQ(result.amount, 20000);
    EXPECT_EQ(result.precision, 2);
}

TEST(AddTest, AddCurrencyNegative) {
    Currency::Currency currency1(100, 2);
    Currency::Currency currency2(-50, 2);

    Currency::Currency result = currency1.add(currency2);

    EXPECT_EQ(result.amount, 5000);
    EXPECT_EQ(result.precision, 2);
}
