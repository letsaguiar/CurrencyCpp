#include <gtest/gtest.h>
#include "currency.hpp"

TEST(LessThan, IntTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThan(101));
}

TEST(LessThan, IntFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThan(100));
}

TEST(LessThan, DoubleTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThan(100.01));
}

TEST(LessThan, DoubleFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThan(100.00));
}

TEST(LessThan, DoubleMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThan(100.555));
}

TEST(LessThan, DoubleMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThan(99.995));
}

TEST(LessThan, StringTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThan("100.01"));
}

TEST(LessThan, StringFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThan("100.00"));
}

TEST(LessThan, StringMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.lessThan("100.555"));
}

TEST(LessThan, StringMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.lessThan("99.995"));
}

TEST(LessThan, CurrencyTrue) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(101, 2);

    EXPECT_TRUE(currency.lessThan(currency2));
}

TEST(LessThan, CurrencyFalse) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(100, 2);

    EXPECT_FALSE(currency.lessThan(currency2));
}

TEST(LessThan, CurrencyMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(100.555, 2);

    EXPECT_TRUE(currency.lessThan(currency2));
}

TEST(LessThan, CurrencyMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(99.555, 2);

    EXPECT_FALSE(currency.lessThan(currency2));
}

TEST(LessThan, CurrencyMinorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(100.555, 1);

    EXPECT_TRUE(currency.lessThan(currency2));
}

TEST(LessThan, CurrencyMinorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(100.01, 1);

    EXPECT_FALSE(currency.lessThan(currency2));
}