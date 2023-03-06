#include "currency.hpp"

bool CurrencyCpp::Currency::lessThanOrEqual(int t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount <= amount;
}

bool CurrencyCpp::Currency::lessThanOrEqual(double t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount <= amount;
}

bool CurrencyCpp::Currency::lessThanOrEqual(std::string t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount <= amount;
}

bool CurrencyCpp::Currency::lessThanOrEqual(Currency t_value) {
    t_value = this->equalizePrecisionHelper(t_value);

    return this->amount <= t_value.amount;
}