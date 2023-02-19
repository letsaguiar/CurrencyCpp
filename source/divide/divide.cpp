#include "currency.hpp"
#include <iostream>

Currency::Currency Currency::Currency::divide(int t_value) {
    int value = t_value * pow(10, this->precision);
    
    double amount = (double)this->amount / (double)value;

    return Currency(amount, this->precision);
}

Currency::Currency Currency::Currency::divide(double t_value) {
    int value = t_value * pow(10, this->precision);

    double amount = (double)this->amount / (double)value;

    return Currency(amount, this->precision);
}

Currency::Currency Currency::Currency::divide(std::string t_value) {
    t_value = this->sanitizeStrValue(t_value);

    int value = std::stod(t_value) * pow(10, this->precision);

    double amount = (double)this->amount / (double)value;

    return Currency(amount, this->precision);
}

Currency::Currency Currency::Currency::divide(Currency t_value) {
    t_value = this->equalizePrecision(t_value);

    double amount = (double)this->amount / (double)t_value.amount;

    return Currency(amount, this->precision);
}