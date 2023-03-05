#include "currency.hpp"

int CurrencyCpp::Currency::extractAmountHelper(int t_value) {
    return t_value * pow(10, this->precision);
}

int CurrencyCpp::Currency::extractAmountHelper(double t_value) {
    return t_value * pow(10, this->precision);
}

int CurrencyCpp::Currency::extractAmountHelper(std::string t_value) {
    t_value = std::regex_replace(t_value, std::regex("[^(0-9)(.)(,)(\\-)]"), "");
    t_value = std::regex_replace(t_value, std::regex("[,]"), ".");

    return std::stod(t_value) * pow(10, this->precision);
}
int CurrencyCpp::Currency::extractAmountHelper(Currency t_value) {
    return t_value.amount;
}

CurrencyCpp::Currency CurrencyCpp::Currency::equalizePrecisionHelper(Currency t_value) {
    double amount = t_value.toUnit();
    return Currency(amount, this->precision);
}