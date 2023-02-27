#include "currency.hpp"

bool Currency::Currency::equalsTo(int t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return amount == this->amount;
}

bool Currency::Currency::equalsTo(double t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return amount == this->amount;
}

bool Currency::Currency::equalsTo(std::string t_value) {
    const int amount = this->extractAmountHelper(t_value);

    return amount == this->amount;
}

bool Currency::Currency::equalsTo(Currency t_value) {
    t_value = this->equalizePrecisionHelper(t_value);

    return t_value.amount == this->amount;
}