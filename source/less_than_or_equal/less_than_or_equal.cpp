#include <gtest/gtest.h>
#include "currency.hpp"

TEST(LessThanOrEqual, IntTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThanOrEqual(100));
    EXPECT_TRUE(currency.lessThanOrEqual(101));
}

TEST(LessThanOrEqual, IntFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThanOrEqual(99));
}

TEST(LessThanOrEqual, DoubleTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThanOrEqual(100.00));
    EXPECT_TRUE(currency.lessThanOrEqual(100.01));
}

TEST(LessThanOrEqual, DoubleFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThanOrEqual(99.99));
}

TEST(LessThanOrEqual, DoubleMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThanOrEqual(100.005));
    EXPECT_TRUE(currency.lessThanOrEqual(100.015));
}

TEST(LessThanOrEqual, DoubleMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThanOrEqual(99.995));
}

TEST(LessThanOrEqual, StringTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThanOrEqual("100.00"));
    EXPECT_TRUE(currency.lessThanOrEqual("100.01"));
}

TEST(LessThanOrEqual, StringFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThanOrEqual("99.99"));
}

TEST(LessThanOrEqual, StringMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThanOrEqual("100.005"));
    EXPECT_TRUE(currency.lessThanOrEqual("100.015"));
}

TEST(LessThanOrEqual, StringMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThanOrEqual("99.995"));
}

TEST(LessThanOrEqual, CurrencyTrue) {
    CurrencyCpp::Currency currency(100, 2);

    CurrencyCpp::Currency currency2(100, 2);
    CurrencyCpp::Currency currency3(100.01, 2);

    EXPECT_TRUE(currency.lessThanOrEqual(currency2));
    EXPECT_TRUE(currency.lessThanOrEqual(currency3));
}

TEST(LessThanOrEqual, CurrencyFalse) {
    CurrencyCpp::Currency currency(100, 2);

    CurrencyCpp::Currency currency2(99.99, 2);

    EXPECT_FALSE(currency.lessThanOrEqual(currency2));
}

TEST(LessThanOrEqual, CurrencyMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);

    CurrencyCpp::Currency currency2(100.005, 3);
    CurrencyCpp::Currency currency3(100.015, 3);

    EXPECT_TRUE(currency.lessThanOrEqual(currency2));
    EXPECT_TRUE(currency.lessThanOrEqual(currency3));
}

TEST(LessThanOrEqual, CurrencyMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);

    CurrencyCpp::Currency currency2(99.995, 3);

    EXPECT_FALSE(currency.lessThanOrEqual(currency2));
}

TEST(LessThanOrEqual, CurrencyMinorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);

    CurrencyCpp::Currency currency2(100, 1);
    CurrencyCpp::Currency currency3(100.1, 1);

    EXPECT_TRUE(currency.lessThanOrEqual(currency2));
    EXPECT_TRUE(currency.lessThanOrEqual(currency3));
}

TEST(LessThanOrEqual, CurrencyMinorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);

    CurrencyCpp::Currency currency2(99.9, 1);

    EXPECT_FALSE(currency.lessThanOrEqual(currency2));
}