#include "currency.hpp"

int Currency::Currency::getPrecision() {
    return this->precision;
}

void Currency::Currency::setPrecision(int t_precision) {
    this->precision = t_precision;
}