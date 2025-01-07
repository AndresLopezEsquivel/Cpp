#include <iostream>
#include <iomanip>

int main()
{
  std::cout << "Current precision: " << std::cout.precision() << std::endl; // Output: 6

  std::cout << std::setw(10) << std::left << "Hello" << std::setw(10) << std::right << "World" << std::endl;
  std::cout << std::setfill('*') << std::setw(10) << std::left << "Hello"
            << std::setfill('-') << std::setw(10) << std::right << "World" << std::endl;


  return 0;
}
