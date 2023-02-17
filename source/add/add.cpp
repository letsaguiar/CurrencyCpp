#include "currency.hpp"

Currency::Currency Currency::Currency::add(int t_value) {
    int value = t_value * pow(10, this->precision) + this->amount;
    double amount = value / pow(10, this->precision);

    return Currency(amount, this->precision);
}

Currency::Currency Currency::Currency::add(double t_value) {
    int value = t_value * pow(10, this->precision) + this->amount;
    double amount = value / pow(10, this->precision);

    return Currency(amount, this->precision);
}

Currency::Currency Currency::Currency::add(std::string t_value) {
    t_value = this->sanitizeStrValue(t_value);

    int value = std::stod(t_value) * pow(10, this->precision) + this->amount;
    double amount = value / pow(10, this->precision);

    return Currency(amount, this->precision);
}

Currency::Currency Currency::Currency::add(Currency t_value) {
    t_value = this->equalizePrecision(t_value);

    int value = t_value.amount + this->amount;
    double amount = value / pow(10, this->precision);

    return Currency(amount, this->precision);
}