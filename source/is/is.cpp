#include "currency.hpp"

bool CurrencyCpp::Currency::isZero() {
    return this->amount == 0;
}

bool CurrencyCpp::Currency::isPositive() {
    return this->amount > 0;
}

bool CurrencyCpp::Currency::isNegative() {
    return this->amount < 0;
}
