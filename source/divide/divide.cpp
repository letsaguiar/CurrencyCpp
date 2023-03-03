#include "currency.hpp"
#include <iostream>

CurrencyCpp::Currency CurrencyCpp::Currency::divide(int t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const double result = (double)this->amount / (double)amount;

    return Currency(result, this->precision);
}

CurrencyCpp::Currency CurrencyCpp::Currency::divide(double t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const double result = (double)this->amount / (double)amount;

    return Currency(result, this->precision);
}

CurrencyCpp::Currency CurrencyCpp::Currency::divide(std::string t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const double result = (double)this->amount / (double)amount;

    return Currency(result, this->precision);
}

CurrencyCpp::Currency CurrencyCpp::Currency::divide(Currency t_value) {
    t_value = this->equalizePrecisionHelper(t_value);

    const int amount = this->extractAmountHelper(t_value);
    const double result = (double)this->amount / (double)amount;

    return Currency(result, this->precision);
}