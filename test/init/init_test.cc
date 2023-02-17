#include <gtest/gtest.h>
#include "currency.hpp"

TEST(IntInitialization, TwoDecimalPlaces) {
  Currency::Currency currency(100, 2);

  EXPECT_EQ(currency.amount, 10000);
  EXPECT_EQ(currency.precision, 2);
}

TEST(IntInitialization, ThreeDecimalPlaces) {
  Currency::Currency currency(100, 3);

  EXPECT_EQ(currency.amount, 100000);
  EXPECT_EQ(currency.precision, 3);
}

TEST(IntInitialization, NegativeValue) {
    Currency::Currency currency(-100, 2);
    
    EXPECT_EQ(currency.amount, -10000);
    EXPECT_EQ(currency.precision, 2);
}

TEST(DoubleInitialization, TwoDecimalPlaces) {
  Currency::Currency currency(100.00, 2);

  EXPECT_EQ(currency.amount, 10000);
  EXPECT_EQ(currency.precision, 2);
}

TEST(DoubleInitialization, ThreeDecimalPlaces) {
  Currency::Currency currency(100.000, 3);

  EXPECT_EQ(currency.amount, 100000);
  EXPECT_EQ(currency.precision, 3);
}

TEST(DoubleInitialization, ValuePrecisionIsLessThanPrecision) {
  Currency::Currency currency(100.1, 2);

  EXPECT_EQ(currency.amount, 10010);
  EXPECT_EQ(currency.precision, 2);
}

TEST(DoubleInitialization, ValuePrecisionIsGreaterThanPrecision) {
  Currency::Currency currency(100.123, 2);

  EXPECT_EQ(currency.amount, 10012);
  EXPECT_EQ(currency.precision, 2);
}

TEST(DoubleInitialization, NegativeValue) {
  Currency::Currency currency(-100.00, 2);

  EXPECT_EQ(currency.amount, -10000);
  EXPECT_EQ(currency.precision, 2);
}

TEST(StringInitialization, TwoDecimalPlaces) {
  Currency::Currency currency("100.00", 2);

  EXPECT_EQ(currency.amount, 10000);
  EXPECT_EQ(currency.precision, 2);
}

TEST(StringInitialization, ThreeDecimalPlaces) {
  Currency::Currency currency("100.000", 3);

  EXPECT_EQ(currency.amount, 100000);
  EXPECT_EQ(currency.precision, 3);
}

TEST(StringInitialization, CommaInsteadOfDot) {
  Currency::Currency currency("100,1", 2);

  EXPECT_EQ(currency.amount, 10010);
  EXPECT_EQ(currency.precision, 2);
}

TEST(StringInitialization, CurrencyCharacters) {
  Currency::Currency currency("R$100.00", 2);

  EXPECT_EQ(currency.amount, 10000);
  EXPECT_EQ(currency.precision, 2);
}

TEST(StringInitialization, NegativeValue) {
  Currency::Currency currency("-100.00", 2);

  EXPECT_EQ(currency.amount, -10000);
  EXPECT_EQ(currency.precision, 2);
}

