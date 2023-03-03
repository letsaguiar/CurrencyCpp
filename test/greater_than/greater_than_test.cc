#include <gtest/gtest.h>
#include "currency.hpp"

TEST(GreaterThan, IntTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThan(99));
}

TEST(GreaterThan, IntFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThan(100));
}

TEST(GreaterThan, DoubleTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThan(99.99));
}

TEST(GreaterThan, DoubleFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThan(100.00));
}

TEST(GreaterThan, DoubleMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThan(99.995));
}

TEST(GreaterThan, DoubleMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThan(100.005));
}

TEST(GreaterThan, StringTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThan("99.99"));
}

TEST(GreaterThan, StringFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThan("100.00"));
}

TEST(GreaterThan, StringMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_TRUE(currency.greaterThan("99.995"));
}

TEST(GreaterThan, StringMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_FALSE(currency.greaterThan("100.005"));
}

TEST(GreaterThan, CurrencyTrue) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(99.99, 2);

    EXPECT_TRUE(currency.greaterThan(currency2));
}

TEST(GreaterThan, CurrencyFalse) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(100, 2);

    EXPECT_FALSE(currency.greaterThan(currency2));
}

TEST(GreaterThan, CurrencyMajorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(99.995, 3);

    EXPECT_TRUE(currency.greaterThan(currency2));
}

TEST(GreaterThan, CurrencyMajorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(100.005, 3);

    EXPECT_FALSE(currency.greaterThan(currency2));
}

TEST(GreaterThan, CurrencyMinorPrecisionTrue) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(99.99, 1);

    EXPECT_TRUE(currency.greaterThan(currency2));
}

TEST(GreaterThan, CurrencyMinorPrecisionFalse) {
    CurrencyCpp::Currency currency(100, 2);
    CurrencyCpp::Currency currency2(100.00, 1);

    EXPECT_FALSE(currency.greaterThan(currency2));
}