#include <string>
#include <cmath>
#include <regex>

namespace Currency {
    class Currency {
        public:
            /**
             * An integer representing the amount of the currency.
            */
            int amount;

            /**
             * The number of decimal places of the currency.
            */
            int precision;
            
            Currency(int amount, int precision);
            Currency(double amount, int precision);
            Currency(std::string amount, int precision);

            /**
             * Returns the amount of the currency.
            */
            int getAmount();

            /**
             * Returns the precision of the currency.
            */
            int getPrecision();

            /**
             * Sets a new precision for the currency.
            */
            void setPrecision(int t_precision);

            /**
             * Returns a new currency object that sums
             * the current currency object with the given one.
            */
            Currency add(Currency t_value);
            Currency add(int t_value);
            Currency add(double t_value);
            Currency add(std::string t_value);

            /**
             * Returns a new currency object that subtracts
             * the given currency object from the current one.
            */
            Currency subtract(Currency t_value);
            Currency subtract(int t_value);
            Currency subtract(double t_value);
            Currency subtract(std::string t_value);

            /**
             * Returns a new currency object that multiplies
             * the current currency object with the given one.
            */
            Currency multiply(Currency t_value);
            Currency multiply(int t_value);
            Currency multiply(double t_value);
            Currency multiply(std::string t_value);

            /**
             * Returns a new currency object that divides
             * the current currency object by the given one.
            */
            Currency divide(Currency t_value);
            Currency divide(int t_value);
            Currency divide(double t_value);
            Currency divide(std::string t_value);

            /**
             * Returns a new currency object that calculates
             * the percentage of the current currency object.
            */
            Currency percentage(Currency t_value);
            Currency percentage(int t_value);
            Currency percentage(double t_value);

            /**
             * Checks if the value of the current currency object
             * is equals to the given one.
            */
            bool equalsTo(Currency t_value);
            bool equalsTo(int t_value);
            bool equalsTo(double t_value);
            bool equalsTo(std::string t_value);

            /**
             * Checks if the value of the current currency object
             * is greater than the given one.
            */
            bool greaterThan(Currency t_value);
            bool greaterThan(int t_value);
            bool greaterThan(double t_value);
            bool greaterThan(std::string t_value);

            /**
             * Checks if the value of the current currency object
             * is greater than the given one.
            */
            bool lessThan(Currency t_value);
            bool lessThan(int t_value);
            bool lessThan(double t_value);
            bool lessThan(std::string t_value);

            /**
             * Checks if the value of the current currency object
             * is greater than or equals to the given one.
            */
            bool greaterThanOrEqual(Currency t_value);
            bool greaterThanOrEqual(int t_value);
            bool greaterThanOrEqual(double t_value);
            bool greaterThanOrEqual(std::string t_value);

            /**
             * Checks if the value of the current currency object
             * is less than or equals to the given one.
            */
            bool lessThanOrEqual(Currency t_value);
            bool lessThanOrEqual(int t_value);
            bool lessThanOrEqual(double t_value);
            bool lessThanOrEqual(std::string t_value);

            /**
             * Checks if the value of the current currency object
             * is zero.
            */
            bool isZero();

            /**
             * Checks if the value of the current currency object
             * is positive.
            */
            bool isPositive();

            /**
             * Checks if the value of the current currency object
             * is negative.
            */
            bool isNegative();

            /**
             * Returns a string representation of the currency object.
            */
            std::string toFormat();

            /**
             * Returns the amount of the currency object in units.
            */
            double toUnit();

            /**
             * Returns the amount of the currency object in units
             * with its cents rounded.
            */
            double toRoundedUnit();

        private:
            /**
             * Transforms the given value to a valid amount.
            */
            int extractAmountHelper(int t_value);
            int extractAmountHelper(double t_value);
            int extractAmountHelper(std::string t_value);
            int extractAmountHelper(Currency t_value);

            /**
             * Transforms the given currency to a new one
             * where the precision is equal to the current one.
            */
            Currency equalizePrecisionHelper(Currency t_value);
    };
}