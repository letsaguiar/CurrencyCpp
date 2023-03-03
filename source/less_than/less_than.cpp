#include "currency.hpp"

bool CurrencyCpp::Currency::lessThan(int t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount < amount;
}

bool CurrencyCpp::Currency::lessThan(double t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount < amount;
}

bool CurrencyCpp::Currency::lessThan(std::string t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount < amount;
}

bool CurrencyCpp::Currency::lessThan(Currency t_value) {
    t_value = this->equalizePrecisionHelper(t_value);

    return this->amount < t_value.amount;
}