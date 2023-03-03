#include <gtest/gtest.h>
#include "currency.hpp"

TEST(LessThanOrEqual, IntTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThanOrEqual(100));
    EXPECT_TRUE(currency.lessThanOrEqual(101));
}

TEST(LessThanOrEqual, IntFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThanOrEqual(99));
}

TEST(LessThanOrEqual, DoubleTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThanOrEqual(100.00));
    EXPECT_TRUE(currency.lessThanOrEqual(100.01));
}

TEST(LessThanOrEqual, DoubleFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThanOrEqual(99.99));
}

TEST(LessThanOrEqual, DoubleMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThanOrEqual(100.005));
    EXPECT_TRUE(currency.lessThanOrEqual(100.015));
}

TEST(LessThanOrEqual, DoubleMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThanOrEqual(99.995));
}

TEST(LessThanOrEqual, StringTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThanOrEqual("100.00"));
    EXPECT_TRUE(currency.lessThanOrEqual("100.01"));
}

TEST(LessThanOrEqual, StringFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThanOrEqual("99.99"));
}

TEST(LessThanOrEqual, StringMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThanOrEqual("100.005"));
    EXPECT_TRUE(currency.lessThanOrEqual("100.015"));
}

TEST(LessThanOrEqual, StringMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThanOrEqual("99.995"));
}

TEST(LessThanOrEqual, CurrencyTrue) {
    Currency::Currency currency(100, 2);

    Currency::Currency currency2(100, 2);
    Currency::Currency currency3(100.01, 2);

    EXPECT_TRUE(currency.lessThanOrEqual(currency2));
    EXPECT_TRUE(currency.lessThanOrEqual(currency3));
}

TEST(LessThanOrEqual, CurrencyFalse) {
    Currency::Currency currency(100, 2);

    Currency::Currency currency2(99.99, 2);

    EXPECT_FALSE(currency.lessThanOrEqual(currency2));
}

TEST(LessThanOrEqual, CurrencyMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);

    Currency::Currency currency2(100.005, 3);
    Currency::Currency currency3(100.015, 3);

    EXPECT_TRUE(currency.lessThanOrEqual(currency2));
    EXPECT_TRUE(currency.lessThanOrEqual(currency3));
}

TEST(LessThanOrEqual, CurrencyMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);

    Currency::Currency currency2(99.995, 3);

    EXPECT_FALSE(currency.lessThanOrEqual(currency2));
}

TEST(LessThanOrEqual, CurrencyMinorPrecisionTrue) {
    Currency::Currency currency(100, 2);

    Currency::Currency currency2(100, 1);
    Currency::Currency currency3(100.1, 1);

    EXPECT_TRUE(currency.lessThanOrEqual(currency2));
    EXPECT_TRUE(currency.lessThanOrEqual(currency3));
}

TEST(LessThanOrEqual, CurrencyMinorPrecisionFalse) {
    Currency::Currency currency(100, 2);

    Currency::Currency currency2(99.9, 1);

    EXPECT_FALSE(currency.lessThanOrEqual(currency2));
}