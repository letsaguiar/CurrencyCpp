#include "currency.hpp"

double CurrencyCpp::Currency::toUnit() {
    return this->amount / pow(10, this->precision);
}

double CurrencyCpp::Currency::toRoundedUnit() {
    return round(this->toUnit());
}