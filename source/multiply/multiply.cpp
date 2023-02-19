#include "currency.hpp"

Currency::Currency Currency::Currency::multiply(int t_value) {
    return Currency(this->amount * t_value, this->precision);
}

Currency::Currency Currency::Currency::multiply(double t_value) {
    return Currency(this->amount * t_value, this->precision);
}

Currency::Currency Currency::Currency::multiply(std::string t_value) {
    return Currency(this->amount * std::stod(t_value), this->precision);
}

Currency::Currency Currency::Currency::multiply(Currency t_value) {
    return Currency(this->amount * t_value.amount, this->precision);
}