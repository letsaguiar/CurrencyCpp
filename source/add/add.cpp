#include "currency.hpp"

Currency::Currency Currency::Currency::add(int t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const int result =  amount + this->amount;
    const double unit = result / pow(10, this->precision);

    return Currency(unit, this->precision);
}

Currency::Currency Currency::Currency::add(double t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const int result =  amount + this->amount;
    const double unit = result / pow(10, this->precision);

    return Currency(unit, this->precision);
}

Currency::Currency Currency::Currency::add(std::string t_value) {
    const int amount = this->extractAmountHelper(t_value);
    const int result =  amount + this->amount;
    const double unit = result / pow(10, this->precision);

    return Currency(unit, this->precision);
}

Currency::Currency Currency::Currency::add(Currency t_value) {
    t_value = this->equalizePrecisionHelper(t_value);
    
    const int amount = this->extractAmountHelper(t_value);
    const int result =  amount + this->amount;
    const double unit = result / pow(10, this->precision);

    return Currency(unit, this->precision);
}