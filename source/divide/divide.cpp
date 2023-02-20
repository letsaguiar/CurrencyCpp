#include "currency.hpp"
#include <iostream>

Currency::Currency Currency::Currency::divide(int t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const double result = (double)this->amount / (double)amount;

    return Currency(result, this->precision);
}

Currency::Currency Currency::Currency::divide(double t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const double result = (double)this->amount / (double)amount;

    return Currency(result, this->precision);
}

Currency::Currency Currency::Currency::divide(std::string t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const double result = (double)this->amount / (double)amount;

    return Currency(result, this->precision);
}

Currency::Currency Currency::Currency::divide(Currency t_value) {
    t_value = this->equalizePrecisionHelper(t_value);

    const int amount = this->extractAmountHelper(t_value);
    const double result = (double)this->amount / (double)amount;

    return Currency(result, this->precision);
}