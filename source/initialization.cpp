#include "currency.hpp"

Currency::Currency::Currency(int amount, int precision) {
    this->amount = amount;
    this->precision = precision;
}

Currency::Currency::Currency(double amount, int precision) {
    this->amount = amount * pow(10, precision);
    this->precision = precision;
}

Currency::Currency::Currency(std::string amount, int precision) {
    this->amount = std::stoi(amount) * pow(10, precision);
    this->precision = precision;
}