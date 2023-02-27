#include <gtest/gtest.h>
#include "currency.hpp"

TEST(GreaterThan, IntTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThan(99));
}

TEST(GreaterThan, IntFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThan(100));
}

TEST(GreaterThan, DoubleTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThan(99.99));
}

TEST(GreaterThan, DoubleFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThan(100.00));
}

TEST(GreaterThan, DoubleMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThan(99.995));
}

TEST(GreaterThan, DoubleMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThan(100.005));
}

TEST(GreaterThan, StringTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThan("99.99"));
}

TEST(GreaterThan, StringFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThan("100.00"));
}

TEST(GreaterThan, StringMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThan("99.995"));
}

TEST(GreaterThan, StringMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThan("100.005"));
}

TEST(GreaterThan, CurrencyTrue) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(99.99, 2);

    EXPECT_TRUE(currency.greaterThan(currency2));
}

TEST(GreaterThan, CurrencyFalse) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(100, 2);

    EXPECT_FALSE(currency.greaterThan(currency2));
}

TEST(GreaterThan, CurrencyMajorPrecisionTrue) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(99.995, 3);

    EXPECT_TRUE(currency.greaterThan(currency2));
}

TEST(GreaterThan, CurrencyMajorPrecisionFalse) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(100.005, 3);

    EXPECT_FALSE(currency.greaterThan(currency2));
}

TEST(GreaterThan, CurrencyMinorPrecisionTrue) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(99.99, 1);

    EXPECT_TRUE(currency.greaterThan(currency2));
}

TEST(GreaterThan, CurrencyMinorPrecisionFalse) {
    Currency::Currency currency(100, 2);
    Currency::Currency currency2(100.00, 1);

    EXPECT_FALSE(currency.greaterThan(currency2));
}