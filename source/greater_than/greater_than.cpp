#include "currency.hpp"

bool Currency::Currency::greaterThan(int t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount > amount;
}

bool Currency::Currency::greaterThan(double t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount > amount;
}

bool Currency::Currency::greaterThan(std::string t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return this->amount > amount;
}

bool Currency::Currency::greaterThan(Currency t_value) {
    t_value = this->equalizePrecisionHelper(t_value);

    return this->amount > t_value.amount;
}