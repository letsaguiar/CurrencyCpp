#include "currency.hpp"

bool Currency::Currency::lessThanOrEqual(int t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount <= amount;
}

bool Currency::Currency::lessThanOrEqual(double t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount <= amount;
}

bool Currency::Currency::lessThanOrEqual(std::string t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount <= amount;
}

bool Currency::Currency::lessThanOrEqual(Currency t_value) {
    t_value = this->equalizePrecisionHelper(t_value);

    return this->amount <= t_value.amount;
}