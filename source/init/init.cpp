#include "currency.hpp"
#include <iostream>

CurrencyCpp::Currency::Currency(int t_amount, int t_precision) {
    this->amount = t_amount * pow(10, t_precision);
    this->precision = t_precision;
}

CurrencyCpp::Currency::Currency(double t_amount, int t_precision) {
    this->amount = t_amount * pow(10, t_precision);
    this->precision = t_precision;
}

CurrencyCpp::Currency::Currency(std::string t_amount, int t_precision) {
    t_amount = std::regex_replace(t_amount, std::regex("[^(0-9)(.)(,)(\\-)]"), "");
    t_amount = std::regex_replace(t_amount, std::regex("[,]"), ".");
    
    this->amount = std::stod(t_amount) * pow(10, t_precision);
    this->precision = t_precision;
}