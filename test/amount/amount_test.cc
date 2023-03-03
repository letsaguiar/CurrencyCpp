#include <gtest/gtest.h>
#include "currency.hpp"

TEST(GetAmountTest, PositiveAmount) {
    CurrencyCpp::Currency currency(100, 2);

    EXPECT_EQ(currency.getAmount(), 10000);
}

TEST(GetAmountTest, NegativeAmount) {
    CurrencyCpp::Currency currency(-100, 2);

    EXPECT_EQ(currency.getAmount(), -10000);
}