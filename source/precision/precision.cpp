#include "currency.hpp"

int CurrencyCpp::Currency::getPrecision() {
    return this->precision;
}

void CurrencyCpp::Currency::setPrecision(int t_precision) {
    const double amount = this->toUnit();

    this->precision = t_precision;
    this->amount = amount * pow(10, this->precision);
}