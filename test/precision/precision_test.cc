#include <gtest/gtest.h>
#include "currency.hpp"

TEST(GetPrecision, GetPrecision) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_EQ(currency.getPrecision(), 2);
}

TEST(SetPrecision, IncreasePrecision) {
    CurrencyCpp::Currency currency(100, 2);

    currency.setPrecision(3);

    EXPECT_EQ(currency.getPrecision(), 3);
    EXPECT_EQ(currency.amount, 100000);
}

TEST(SetPrecision, DecreasePrecision) {
    CurrencyCpp::Currency currency(100.52, 2);

    currency.setPrecision(1);

    EXPECT_EQ(currency.getPrecision(), 1);
    EXPECT_EQ(currency.amount, 1005);
}