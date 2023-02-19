#include "currency.hpp"

Currency::Currency Currency::Currency::subtract(int t_value) {
    int value = this->amount - t_value * pow(10, this->precision);
    double amount = value / pow(10, this->precision);

    return Currency(amount, this->precision);
}

Currency::Currency Currency::Currency::subtract(double t_value) {
    int value = t_value * pow(10, this->precision);
    value = this->amount - value;
    
    double amount = value / pow(10, this->precision);

    return Currency(amount, this->precision);
}

Currency::Currency Currency::Currency::subtract(std::string t_value) {
    t_value = this->sanitizeStrValue(t_value);

    int value = this->amount - std::stod(t_value) * pow(10, this->precision);
    double amount = value / pow(10, this->precision);

    return Currency(amount, this->precision);
}

Currency::Currency Currency::Currency::subtract(Currency t_value) {
    t_value = this->equalizePrecision(t_value);

    int value = this->amount - t_value.amount;
    double amount = value / pow(10, this->precision);

    return Currency(amount, this->precision);
}