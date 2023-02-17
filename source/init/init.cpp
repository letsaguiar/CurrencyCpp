#include "currency.hpp"

Currency::Currency::Currency(int amount, int precision) {
    this->amount = amount * pow(10, precision);
    this->precision = precision;
}

Currency::Currency::Currency(double amount, int precision) {
    this->amount = amount * pow(10, precision);
    this->precision = precision;
}

Currency::Currency::Currency(std::string amount, int precision) {
    amount = this->sanitizeStrValue(amount);

    this->amount = std::stod(amount) * pow(10, precision);
    this->precision = precision;
}