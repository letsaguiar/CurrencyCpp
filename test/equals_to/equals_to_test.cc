#include <gtest/gtest.h>
#include "currency.hpp"

TEST(EqualsTo, IntTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.equalsTo(100));
}

TEST(EqualsTo, IntFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.equalsTo(200));
}

TEST(EqualsTo, DoubleTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.equalsTo(100.00));
}

TEST(EqualsTo, DoubleFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.equalsTo(100.05));
}

TEST(EqualsTo, DoubleMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.equalsTo(100.005));
}

TEST(EqualsTo, DoubleMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.equalsTo(100.051));
}

TEST(EqualsTo, StringTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.equalsTo("100.00"));
}

TEST(EqualsTo, StringFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.equalsTo("100.05"));
}

TEST(EqualsTo, StringMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.equalsTo("100.005"));
}

TEST(EqualsTo, StringMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.equalsTo("100.051"));
}

TEST(EqualsTo, CurrencyTrue) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(100, 2);

    EXPECT_TRUE(currency.equalsTo(currency2));
}

TEST(EqualsTo, CurrencyFalse) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(200, 2);

    EXPECT_FALSE(currency.equalsTo(currency2));
}

TEST(EqualsTo, CurrencyMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(100, 3);

    EXPECT_TRUE(currency.equalsTo(currency2));
}

TEST(EqualsTo, CurrencyMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(100.02, 3);

    EXPECT_FALSE(currency.equalsTo(currency2));
}

TEST(EqualsTo, CurrencyMinorPrecisionTrue) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(100, 1);

    EXPECT_TRUE(currency.equalsTo(currency2));
}

TEST(EqualsTo, CurrencyMinorPrecisionFalse) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(100.1, 1);

    EXPECT_FALSE(currency.equalsTo(currency2));
}