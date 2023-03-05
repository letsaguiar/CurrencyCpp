# CurrencyCpp 

CurrencyCpp is a library that uses all the power of Object-Oriented Programming to perform correct operations and comparisons when working with decimal point values.

To ensure the accuracy of the calculations, all operations are performed using integer values. So when you're using CurrencyCpp you can define your calculus' precision, perform operations and comparisions and convert it to a native double type knowing that the desired precision is being maintained.

It stores values in a 64-bit signed int so the max number of digits (including integers and fractional parts) are 18. If your settings or calculations exceed this value, unexpected behavior may occur.

## Instalation

## Usage
To get started using CurrencyCpp you just need to import it, instantiate a new currency and call the desired methods.

```
#include <currency.hpp>
#include <iostream>

CurrencyCpp::Currency value(100, 2);
value = value.add(100);

std::cout << value.toUnit() << std::endl; // 200.00
```

```
#include <currency.hpp>
#include <iostream>

CurrencyCpp::Currency value(100, 2);

if (value.equalsTo(100)) {
    std::cout << value.toUnit() << std::endl; // 100.00
}
```

## Testing

## Contributing

## Acknowledgements

## License