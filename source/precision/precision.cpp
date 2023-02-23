#include "currency.hpp"

int Currency::Currency::getPrecision() {
    return this->precision;
}

void Currency::Currency::setPrecision(int t_precision) {
    // TODO: Implement toUnit and refactor
    const double amount = this->amount / pow(10, this->precision);

    this->precision = t_precision;
    this->amount = amount * pow(10, this->precision);
}