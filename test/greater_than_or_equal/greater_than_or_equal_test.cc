#include <gtest/gtest.h>
#include "currency.hpp"

TEST(GreaterThanOrEqual, IntTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThanOrEqual(99));
    EXPECT_TRUE(currency.greaterThanOrEqual(100));
}

TEST(GreaterThanOrEqual, IntFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThanOrEqual(101));
}

TEST(GreaterThanOrEqual, DoubleTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThanOrEqual(99.99));
    EXPECT_TRUE(currency.greaterThanOrEqual(100.00));
}

TEST(GreaterThanOrEqual, DoubleFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThanOrEqual(100.01));
}

TEST(GreaterThanOrEqual, DoubleMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThanOrEqual(99.995));
    EXPECT_TRUE(currency.greaterThanOrEqual(100.005));
}

TEST(GreaterThanOrEqual, DoubleMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThanOrEqual(100.015));
}

TEST(GreaterThanOrEqual, StringTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThanOrEqual("99.99"));
    EXPECT_TRUE(currency.greaterThanOrEqual("100.00"));
}

TEST(GreaterThanOrEqual, StringFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThanOrEqual("100.01"));
}

TEST(GreaterThanOrEqual, StringMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThanOrEqual("99.995"));
    EXPECT_TRUE(currency.greaterThanOrEqual("100.005"));
}

TEST(GreaterThanOrEqual, StringMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThanOrEqual("100.015"));
}

TEST(GreaterThanOrEqual, CurrencyTrue) {
    Currency::Currency currency(100, 2);

    Currency::Currency currency2(99, 2);
    Currency::Currency currency3(100, 2);

    EXPECT_TRUE(currency.greaterThanOrEqual(currency2));
    EXPECT_TRUE(currency.greaterThanOrEqual(currency3));
}

TEST(GreaterThanOrEqual, CurrencyFalse) {
    Currency::Currency currency(100, 2);

    Currency::Currency currency2(101, 2);

    EXPECT_FALSE(currency.greaterThanOrEqual(currency2));
}

TEST(GreaterThanOrEqual, CurrencyMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);

    Currency::Currency currency2(99, 3);
    Currency::Currency currency3(100, 3);

    EXPECT_TRUE(currency.greaterThanOrEqual(currency2));
    EXPECT_TRUE(currency.greaterThanOrEqual(currency3));
}

TEST(GreaterThanOrEqual, CurrencyMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);

    Currency::Currency currency2(101, 3);

    EXPECT_FALSE(currency.greaterThanOrEqual(currency2));
}

TEST(GreaterThanOrEqual, CurrencyMinorPrecisionTrue) {
    Currency::Currency currency(100, 2);

    Currency::Currency currency2(99, 1);
    Currency::Currency currency3(100, 1);

    EXPECT_TRUE(currency.greaterThanOrEqual(currency2));
    EXPECT_TRUE(currency.greaterThanOrEqual(currency3));
}

TEST(GreaterThanOrEqual, CurrencyMinorPrecisionFalse) {
    Currency::Currency currency(100, 2);

    Currency::Currency currency2(101, 1);

    EXPECT_FALSE(currency.greaterThanOrEqual(currency2));
}