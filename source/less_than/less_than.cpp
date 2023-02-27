#include "currency.hpp"

bool Currency::Currency::lessThan(int t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount < amount;
}

bool Currency::Currency::lessThan(double t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount < amount;
}

bool Currency::Currency::lessThan(std::string t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount < amount;
}

bool Currency::Currency::lessThan(Currency t_value) {
    t_value = this->equalizePrecisionHelper(t_value);

    return this->amount < t_value.amount;
}