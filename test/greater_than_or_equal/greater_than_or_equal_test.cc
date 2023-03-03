#include <gtest/gtest.h>
#include "currency.hpp"

TEST(GreaterThanOrEqual, IntTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThanOrEqual(99));
    EXPECT_TRUE(currency.greaterThanOrEqual(100));
}

TEST(GreaterThanOrEqual, IntFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThanOrEqual(101));
}

TEST(GreaterThanOrEqual, DoubleTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThanOrEqual(99.99));
    EXPECT_TRUE(currency.greaterThanOrEqual(100.00));
}

TEST(GreaterThanOrEqual, DoubleFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThanOrEqual(100.01));
}

TEST(GreaterThanOrEqual, DoubleMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThanOrEqual(99.995));
    EXPECT_TRUE(currency.greaterThanOrEqual(100.005));
}

TEST(GreaterThanOrEqual, DoubleMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThanOrEqual(100.015));
}

TEST(GreaterThanOrEqual, StringTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThanOrEqual("99.99"));
    EXPECT_TRUE(currency.greaterThanOrEqual("100.00"));
}

TEST(GreaterThanOrEqual, StringFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThanOrEqual("100.01"));
}

TEST(GreaterThanOrEqual, StringMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThanOrEqual("99.995"));
    EXPECT_TRUE(currency.greaterThanOrEqual("100.005"));
}

TEST(GreaterThanOrEqual, StringMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThanOrEqual("100.015"));
}

TEST(GreaterThanOrEqual, CurrencyTrue) {
    CurrencyCpp::Currency currency(100, 2);

    CurrencyCpp::Currency currency2(99, 2);
    CurrencyCpp::Currency currency3(100, 2);

    EXPECT_TRUE(currency.greaterThanOrEqual(currency2));
    EXPECT_TRUE(currency.greaterThanOrEqual(currency3));
}

TEST(GreaterThanOrEqual, CurrencyFalse) {
    CurrencyCpp::Currency currency(100, 2);

    CurrencyCpp::Currency currency2(101, 2);

    EXPECT_FALSE(currency.greaterThanOrEqual(currency2));
}

TEST(GreaterThanOrEqual, CurrencyMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);

    CurrencyCpp::Currency currency2(99, 3);
    CurrencyCpp::Currency currency3(100, 3);

    EXPECT_TRUE(currency.greaterThanOrEqual(currency2));
    EXPECT_TRUE(currency.greaterThanOrEqual(currency3));
}

TEST(GreaterThanOrEqual, CurrencyMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);

    CurrencyCpp::Currency currency2(101, 3);

    EXPECT_FALSE(currency.greaterThanOrEqual(currency2));
}

TEST(GreaterThanOrEqual, CurrencyMinorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);

    CurrencyCpp::Currency currency2(99, 1);
    CurrencyCpp::Currency currency3(100, 1);

    EXPECT_TRUE(currency.greaterThanOrEqual(currency2));
    EXPECT_TRUE(currency.greaterThanOrEqual(currency3));
}

TEST(GreaterThanOrEqual, CurrencyMinorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);

    CurrencyCpp::Currency currency2(101, 1);

    EXPECT_FALSE(currency.greaterThanOrEqual(currency2));
}