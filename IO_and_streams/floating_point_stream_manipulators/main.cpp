#include <iostream>
#include <iomanip>

int main()
{
  std::cout << "Current precision: " << std::cout.precision() << std::endl; // Output: 6
  //The default precision of std::cout is 6 significant digits for floating-point values
  // This precision applies to the entire number, not just the digits after the decimal point.
  std::cout << 1234.5678 << std::endl; // Output: 1234.57
  std::cout << 12345.678 << std::endl; // Output: 12345.7
  std::cout << 123456.78 << std::endl; // Output: 123457
  std::cout << 1234567.8 << std::endl; // Output: 1.23457e+06
  std::cout << 12345678.0 << std::endl; // Output: 1.23457e+07
  std::cout << 123456789.0 << std::endl; // Output: 1.23457e+08
  std::cout << 123456789 << std::endl; // Output: 123456789

  // The std::fixed manipulator in C++ controls how floating-point numbers are displayed in output streams like std::cout
  // It ensures that numbers are displayed in fixed-point notation, meaning the number is formatted with a fixed number of digits after the decimal point.
  // Without std::fixed, the precision you set applies to the total significant digits in the number, not just the digits after the decimal point.
  // When you use std::fixed, the precision applies only to the digits after the decimal point.
  std::cout << "== == ==" << std::endl;
  std::cout << std::fixed; // Will display 6 digits after the decimal point (6 because precision is 6 by default)
  std::cout << 1234.5678 << std::endl; // Output: 1234.567800
  std::cout << 12345678.0 << std::endl; // Output: 12345678.000000

  std::cout << "== == ==" << std::endl;
  std::cout << std::defaultfloat; // Will display the default precision (6 digits after the decimal point)
  std::cout << 1234.5678 << std::endl; // Output: 1234.57
  std::cout << 12345678.0 << std::endl; // Output: 1.23457e+07

  std::cout << "== == ==" << std::endl;
  std::cout << std::setprecision(3) << std::fixed; // Will display 3 digits after the decimal point
  std::cout << 1234.5678 << std::endl; // Output: 1234.568
  std::cout << 12345678.0 << std::endl; // Output: 12345678.000

  std::cout << "== == ==" << std::endl;
  std::cout << std::setprecision(3) << std::scientific;
  std::cout << 1234.5678 << std::endl; // Output: 1.235e+03
  std::cout << 12345678.0 << std::endl; // Output: 1.235e+07

  std::cout << "== == ==" << std::endl;
  std::cout.unsetf(std::ios::fixed | std::ios::scientific); // Unset the fixed and scientific flags
  std::cout << std::setprecision(6);
  std::cout << std::defaultfloat;
  std::cout << "Current precision: " << std::cout.precision() << std::endl;
  std::cout << 12.34 << std::endl; // Output: 12.34
  std::cout << std::showpoint; // Will display trailing zeros
  std::cout << 12.34 << std::endl; // Output: 12.3400


  return 0;
}
