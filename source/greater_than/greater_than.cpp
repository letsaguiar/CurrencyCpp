#include "currency.hpp"

bool CurrencyCpp::Currency::greaterThan(int t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount > amount;
}

bool CurrencyCpp::Currency::greaterThan(double t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount > amount;
}

bool CurrencyCpp::Currency::greaterThan(std::string t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount > amount;
}

bool CurrencyCpp::Currency::greaterThan(Currency t_value) {
    t_value = this->equalizePrecisionHelper(t_value);

    return this->amount > t_value.amount;
}