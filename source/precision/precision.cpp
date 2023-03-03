#include "currency.hpp"

int CurrencyCpp::Currency::getPrecision() {
    return this->precision;
}

void CurrencyCpp::Currency::setPrecision(int t_precision) {
    // TODO: Implement toUnit and refactor
    const double amount = this->amount / pow(10, this->precision);

    this->precision = t_precision;
    this->amount = amount * pow(10, this->precision);
}