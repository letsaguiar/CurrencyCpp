#include "currency.hpp"

CurrencyCpp::Currency CurrencyCpp::Currency::multiply(int t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const int result = this->amount * amount;
    const double unit = result / pow(100, this->precision);

    return Currency(unit, this->precision);
}

CurrencyCpp::Currency CurrencyCpp::Currency::multiply(double t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const int result = this->amount * amount;
    const double unit = result / pow(100, this->precision);

    return Currency(unit, this->precision);
}

CurrencyCpp::Currency CurrencyCpp::Currency::multiply(std::string t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const int result = this->amount * amount;
    const double unit = result / pow(100, this->precision);

    return Currency(unit, this->precision);
}

CurrencyCpp::Currency CurrencyCpp::Currency::multiply(Currency t_value) {
    t_value = this->equalizePrecisionHelper(t_value);

    const int amount = this->extractAmountHelper(t_value);
    const int result = this->amount * amount;
    const double unit = result / pow(100, this->precision);

    return Currency(unit, this->precision);
}