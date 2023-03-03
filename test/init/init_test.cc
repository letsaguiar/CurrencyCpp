#include <gtest/gtest.h>
#include "currency.hpp"

TEST(IntInitialization, TwoDecimalPlaces) {
  CurrencyCpp::Currency currency(100, 2);

  EXPECT_EQ(currency.amount, 10000);
  EXPECT_EQ(currency.precision, 2);
}

TEST(IntInitialization, ThreeDecimalPlaces) {
  CurrencyCpp::Currency currency(100, 3);

  EXPECT_EQ(currency.amount, 100000);
  EXPECT_EQ(currency.precision, 3);
}

TEST(IntInitialization, NegativeValue) {
    CurrencyCpp::Currency currency(-100, 2);
    
    EXPECT_EQ(currency.amount, -10000);
    EXPECT_EQ(currency.precision, 2);
}

TEST(DoubleInitialization, TwoDecimalPlaces) {
  CurrencyCpp::Currency currency(100.00, 2);

  EXPECT_EQ(currency.amount, 10000);
  EXPECT_EQ(currency.precision, 2);
}

TEST(DoubleInitialization, ThreeDecimalPlaces) {
  CurrencyCpp::Currency currency(100.000, 3);

  EXPECT_EQ(currency.amount, 100000);
  EXPECT_EQ(currency.precision, 3);
}

TEST(DoubleInitialization, ValuePrecisionIsLessThanPrecision) {
  CurrencyCpp::Currency currency(100.1, 2);

  EXPECT_EQ(currency.amount, 10010);
  EXPECT_EQ(currency.precision, 2);
}

TEST(DoubleInitialization, ValuePrecisionIsGreaterThanPrecision) {
  CurrencyCpp::Currency currency(100.123, 2);

  EXPECT_EQ(currency.amount, 10012);
  EXPECT_EQ(currency.precision, 2);
}

TEST(DoubleInitialization, NegativeValue) {
  CurrencyCpp::Currency currency(-100.00, 2);

  EXPECT_EQ(currency.amount, -10000);
  EXPECT_EQ(currency.precision, 2);
}

TEST(StringInitialization, TwoDecimalPlaces) {
  CurrencyCpp::Currency currency("100.00", 2);

  EXPECT_EQ(currency.amount, 10000);
  EXPECT_EQ(currency.precision, 2);
}

TEST(StringInitialization, ThreeDecimalPlaces) {
  CurrencyCpp::Currency currency("100.000", 3);

  EXPECT_EQ(currency.amount, 100000);
  EXPECT_EQ(currency.precision, 3);
}

TEST(StringInitialization, CommaInsteadOfDot) {
  CurrencyCpp::Currency currency("100,1", 2);

  EXPECT_EQ(currency.amount, 10010);
  EXPECT_EQ(currency.precision, 2);
}

TEST(StringInitialization, CurrencyCharacters) {
  CurrencyCpp::Currency currency("R$100.00", 2);

  EXPECT_EQ(currency.amount, 10000);
  EXPECT_EQ(currency.precision, 2);
}

TEST(StringInitialization, NegativeValue) {
  CurrencyCpp::Currency currency("-100.00", 2);

  EXPECT_EQ(currency.amount, -10000);
  EXPECT_EQ(currency.precision, 2);
}

