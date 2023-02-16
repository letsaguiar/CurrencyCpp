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
    amount = std::regex_replace(amount, std::regex("[^(0-9)(.)(,)(\\-)]"), "");
    amount = std::regex_replace(amount, std::regex("[,]"), ".");

    this->amount = std::stod(amount) * pow(10, precision);
    this->precision = precision;
}