#include "currency.hpp"
#include <iostream>

Currency::Currency Currency::Currency::percentage(double t_value) {
    if (t_value < 0) {
        throw std::invalid_argument("Percentage value must be greater than 0");
    }

    const double amount = t_value / 100 * this->amount;
    const double result = amount / pow(10, this->precision);

    return Currency(result, this->precision);
}