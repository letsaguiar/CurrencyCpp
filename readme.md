# CurrencyCpp 

CurrencyCpp is a library that uses all the power of Object-Oriented Programming to perform correct operations and comparisons when working with decimal point values.

To ensure the accuracy of the calculations, all operations are performed using integer values. So when you're using CurrencyCpp you can define your calculus' precision, perform operations and comparisions and convert it to a native double type knowing that the desired precision is being maintained.

It stores values in a 64-bit signed int so the max number of digits (including integers and fractional parts) are 18. If your settings or calculations exceed this value, unexpected behavior may occur.

## Installation with CMake

### Cloning Strategy
First, clone this repository into your own project.

```
https://github.com/letsaguiar/CurrencyCpp.git
```

Then, add it as a subdirectory to CMakeLists.txt

```
add_subdirectory(<path_to_currencycpp>)
```

Finally, just link it as a library to your targets

```
target_link_libraries(LinkExample CurrencyCpp)
```

### Fetch Strategy
You can also install without cloning the repository directly. Just add it as FetchContent to your CMakeLists.txt

```
include(FetchContent)
FetchContent_Declare(
  currencycpp
  URL https://github.com/letsaguiar/CurrencyCpp/archive/refs/tags/v1.0.0.zip
)
FetchContent_MakeAvailable(currencycpp)
```

Then link it as a library to your targets

```
target_link_libraries(LinkExample CurrencyCpp)
```


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
To run CurrencyCpp's tests, build the project

```
cmake -B build && cmake --build build
```

Then enter into build folder and call ctest

```
cd build && ctest
```

It should provide you an output like that

```
100% tests passed, 0 tests failed out of 151

Total Test time (real) =   0.48 sec
```

## Acknowledgements
This repo was inspired by [Dinero.js](https://github.com/dinerojs/dinero.js).