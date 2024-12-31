#include <iostream>
#include <string>

double divide(int a, int b)
{
  if (b == 0)
    throw 0; // Instead of throwing a primitive type, we would normally throw an exception object.

  if(a < 0 || b < 0)
    throw std::string("No negative numbers allowed.");

  return static_cast<double>(a) / b; // This to be a floating point division, we need to cast either 'a' or 'b' (or both) to double.
}

int main()
{
  // Divide by zero example

  int a {};
  int b {};
  double c {};

  std::cout << "Provide a value for 'a': ";
  std::cin >> a;

  std::cout << std::endl << "Provide a value for 'b': ";
  std::cin >> b;

  try
  {
    // if (b == 0)
    //   throw 0; // Instead of throwing a primitive type, we would normally throw an exception object.
    // c = static_cast<double>(a) / b; // This to be a floating point division, we need to cast either 'a' or 'b' (or both) to double.
    c = divide(a, b);
    std::cout << std::endl << "c: " << c << std::endl;
  }
  catch(int &e)
  {
    std::cout << std::endl << "Could'nt calculate 'c' because 'b' is zero. " << std::endl;
    std::cerr << "e: " << e << std::endl; // Output: 0
  }
  catch(std::string &str)
  {
    std::cerr << "str: " << str << std::endl; // Output: No negative numbers allowed.
  }
  catch(...) // Catch all other exceptions
  {
    std::cerr << "Unkown exception" << std::endl;
  }

  return 0;
}
