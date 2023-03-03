#include "currency.hpp"

bool CurrencyCpp::Currency::greaterThanOrEqual(int t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount >= amount;
}

bool CurrencyCpp::Currency::greaterThanOrEqual(double t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount >= amount;
}

bool CurrencyCpp::Currency::greaterThanOrEqual(std::string t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount >= amount;
}

bool CurrencyCpp::Currency::greaterThanOrEqual(Currency t_value) {
    t_value = this->equalizePrecisionHelper(t_value);

    return this->amount >= t_value.amount;
}