#include "currency.hpp"

bool Currency::Currency::greaterThanOrEqual(int t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount >= amount;
}

bool Currency::Currency::greaterThanOrEqual(double t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount >= amount;
}

bool Currency::Currency::greaterThanOrEqual(std::string t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount >= amount;
}

bool Currency::Currency::greaterThanOrEqual(Currency t_value) {
    t_value = this->equalizePrecisionHelper(t_value);

    return this->amount >= t_value.amount;
}