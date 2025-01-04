#include <iostream>
#include <iomanip>

int main()
{
  int num {255};
  std::cout << std::dec << num << std::endl; // Output: 255
  std::cout << std::hex << num << std::endl; // Output: ff
  std::cout << std::oct << num << std::endl; // Output: 377

  std::cout << "== == ==" << std::endl;
  // Same as std::cout.setf(std::ios::showbase);
  std::cout << std::showbase; // Causes the base of the number to be shown (0x for hex, 0 for octal)
  std::cout << std::dec << num << std::endl; // Output: 255
  std::cout << std::hex << num << std::endl; // Output: 0xff
  std::cout << std::oct << num << std::endl; // Output: 0377

  std::cout << "== == ==" << std::endl;
  // Same as std::cout.setf(std::ios::uppercase);
  std::cout << std::uppercase; // Causes the letters in the output to be uppercase
  std::cout << std::dec << num << std::endl; // Output: 255
  std::cout << std::hex << num << std::endl; // Output: 0XFF
  std::cout << std::oct << num << std::endl; // Output: 0377

  std::cout << "== == ==" << std::endl;
  // Same as std::cout.setf(std::ios::showpos);
  std::cout << std::showpos; // Causes the positive numbers to be preceded by a plus sign
  std::cout << std::dec << num << std::endl; // Output: +255
  std::cout << std::hex << num << std::endl; // Output: 0xff
  std::cout << std::oct << num << std::endl; // Output: 0377

  // std::resetiosflags() is a function that clears the format flags of the stream.
  std::cout << std::resetiosflags(std::ios::basefield);
  std::cout << std::resetiosflags(std::ios::showbase);
  std::cout << std::resetiosflags(std::ios::showpos);
  std::cout << std::resetiosflags(std::ios::uppercase);
  return 0;
}
