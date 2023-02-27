#include <gtest/gtest.h>
#include "currency.hpp"

TEST(LessThan, IntTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThan(101));
}

TEST(LessThan, IntFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThan(100));
}

TEST(LessThan, DoubleTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThan(100.01));
}

TEST(LessThan, DoubleFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThan(100.00));
}

TEST(LessThan, DoubleMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThan(100.555));
}

TEST(LessThan, DoubleMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThan(99.995));
}

TEST(LessThan, StringTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThan("100.01"));
}

TEST(LessThan, StringFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThan("100.00"));
}

TEST(LessThan, StringMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThan("100.555"));
}

TEST(LessThan, StringMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThan("99.995"));
}

TEST(LessThan, CurrencyTrue) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(101, 2);

    EXPECT_TRUE(currency.lessThan(currency2));
}

TEST(LessThan, CurrencyFalse) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(100, 2);

    EXPECT_FALSE(currency.lessThan(currency2));
}

TEST(LessThan, CurrencyMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(100.555, 2);

    EXPECT_TRUE(currency.lessThan(currency2));
}

TEST(LessThan, CurrencyMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(99.555, 2);

    EXPECT_FALSE(currency.lessThan(currency2));
}

TEST(LessThan, CurrencyMinorPrecisionTrue) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(100.555, 1);

    EXPECT_TRUE(currency.lessThan(currency2));
}

TEST(LessThan, CurrencyMinorPrecisionFalse) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(100.01, 1);

    EXPECT_FALSE(currency.lessThan(currency2));
}