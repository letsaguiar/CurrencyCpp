#include "currency.hpp"

Currency::Currency Currency::Currency::divide(double t_value) {
    return Currency(this->amount / t_value, precision);
}

Currency::Currency Currency::Currency::divide(int t_value) {
    return Currency(this->amount / t_value, precision);
}

Currency::Currency Currency::Currency::divide(std::string t_value) {
    return Currency(this->amount / std::stod(t_value), precision);
}

Currency::Currency Currency::Currency::divide(Currency t_value) {
    return Currency(this->amount / t_value.amount, precision);
}