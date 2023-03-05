#include <gtest/gtest.h>
#include "currency.hpp"

TEST(ToUnit, OneDecimalPlace) {
    CurrencyCpp::Currency currency(1.1, 1);

    EXPECT_EQ(currency.toUnit(), 1.1);
}

TEST(ToUnit, TwoDecimalPlaces) {
    CurrencyCpp::Currency currency(1.11, 2);

    EXPECT_EQ(currency.toUnit(), 1.11);
}

TEST(ToUnit, ThreeDecimalPlaces) {
    CurrencyCpp::Currency currency(1.111, 3);

    EXPECT_EQ(currency.toUnit(), 1.111);
}

TEST(ToRoundedUnit, Floor) {
    CurrencyCpp::Currency currency(1.1, 2);

    EXPECT_EQ(currency.toRoundedUnit(), 1.0);
}

TEST(ToRoundedUnit, Ceil) {
    CurrencyCpp::Currency currency(1.6, 2);

    EXPECT_EQ(currency.toRoundedUnit(), 2.0);
}