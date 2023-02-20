#include "currency.hpp"

int Currency::Currency::extractAmountHelper(int t_value) {
    return t_value * pow(10, this->precision);
}

int Currency::Currency::extractAmountHelper(double t_value) {
    return t_value * pow(10, this->precision);
}

int Currency::Currency::extractAmountHelper(std::string t_value) {
    t_value = std::regex_replace(t_value, std::regex("[^(0-9)(.)(,)(\\-)]"), "");
    t_value = std::regex_replace(t_value, std::regex("[,]"), ".");

    return std::stod(t_value) * pow(10, this->precision);
}
int Currency::Currency::extractAmountHelper(Currency t_value) {
    return t_value.amount;
}

Currency::Currency Currency::Currency::equalizePrecisionHelper(Currency t_value) {
    // TODO: Implement toUnit and refactor
    double amount = t_value.amount / pow(10, t_value.precision);
    return Currency(amount, this->precision);
}