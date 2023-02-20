#include "currency.hpp"

Currency::Currency Currency::Currency::subtract(int t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const int result =  this->amount - amount;
    const double unit = result / pow(10, this->precision);

    return Currency(unit, this->precision);
}

Currency::Currency Currency::Currency::subtract(double t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const int result =  this->amount - amount;
    const double unit = result / pow(10, this->precision);

    return Currency(unit, this->precision);
}

Currency::Currency Currency::Currency::subtract(std::string t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const int result =  this->amount - amount;
    const double unit = result / pow(10, this->precision);

    return Currency(unit, this->precision);
}

Currency::Currency Currency::Currency::subtract(Currency t_value) {
    t_value = this->equalizePrecisionHelper(t_value);

    const int amount = this->extractAmountHelper(t_value);
    const int result =  this->amount - amount;
    const double unit = result / pow(10, this->precision);

    return Currency(unit, this->precision);
}