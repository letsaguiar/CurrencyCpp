#include "currency.hpp"

bool Currency::Currency::isZero() {
    return this->amount == 0;
}

bool Currency::Currency::isPositive() {
    return this->amount > 0;
}

bool Currency::Currency::isNegative() {
    return this->amount < 0;
}
