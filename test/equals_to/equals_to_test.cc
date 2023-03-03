#include <gtest/gtest.h>
#include "currency.hpp"

TEST(EqualsTo, IntTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.equalsTo(100));
}

TEST(EqualsTo, IntFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.equalsTo(200));
}

TEST(EqualsTo, DoubleTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.equalsTo(100.00));
}

TEST(EqualsTo, DoubleFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.equalsTo(100.05));
}

TEST(EqualsTo, DoubleMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.equalsTo(100.005));
}

TEST(EqualsTo, DoubleMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.equalsTo(100.051));
}

TEST(EqualsTo, StringTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.equalsTo("100.00"));
}

TEST(EqualsTo, StringFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.equalsTo("100.05"));
}

TEST(EqualsTo, StringMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.equalsTo("100.005"));
}

TEST(EqualsTo, StringMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.equalsTo("100.051"));
}

TEST(EqualsTo, CurrencyTrue) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(100, 2);

    EXPECT_TRUE(currency.equalsTo(currency2));
}

TEST(EqualsTo, CurrencyFalse) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(200, 2);

    EXPECT_FALSE(currency.equalsTo(currency2));
}

TEST(EqualsTo, CurrencyMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(100, 3);

    EXPECT_TRUE(currency.equalsTo(currency2));
}

TEST(EqualsTo, CurrencyMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(100.02, 3);

    EXPECT_FALSE(currency.equalsTo(currency2));
}

TEST(EqualsTo, CurrencyMinorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(100, 1);

    EXPECT_TRUE(currency.equalsTo(currency2));
}

TEST(EqualsTo, CurrencyMinorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(100.1, 1);

    EXPECT_FALSE(currency.equalsTo(currency2));
}