#include <iostream>
#include <iomanip>

int main()
{
  // C++ stream manipulators are functions or objects that modify the behavior
  // of input and output streams, such as std::cin and std::cout.
  // They allow you to format the way data is read or written, making streams more flexible and customizable.


  std::cout << "====" << std::endl;

  std::cout << "(30 == 30): " << (30 == 30) << std::endl;
  std::cout << "(30 == 10): " << (30 == 10) << std::endl;

  std::cout << "====" << std::endl;

  std::cout << std::boolalpha; // std::boolalpha is a stream manipulator that causes the output of boolean values to be "true" or "false" instead of 1 or 0.
  std::cout << "(30 == 30): " << (30 == 30) << std::endl;
  std::cout << "(30 == 10): " << (30 == 10) << std::endl;

  std::cout << "====" << std::endl;

  std::cout << std::noboolalpha; // std::noboolalpha is a stream manipulator that causes the output of boolean values to be 1 or 0 instead of "true" or "false".
  std::cout << "(30 == 30): " << (30 == 30) << std::endl;
  std::cout << "(30 == 10): " << (30 == 10) << std::endl;

  std::cout << "====" << std::endl;

  std::cout.setf(std::ios::boolalpha); // setf() is a member function of std::ios_base that sets the format flags of the stream.
  std::cout << "(30 == 30): " << (30 == 30) << std::endl;
  std::cout << "(30 == 10): " << (30 == 10) << std::endl;

  std::cout << "====" << std::endl;

  std::cout << std::resetiosflags(std::ios::boolalpha); // std::resetiosflags() is a function that clears the format flags of the stream.
  std::cout << "(30 == 30): " << (30 == 30) << std::endl;
  std::cout << "(30 == 10): " << (30 == 10) << std::endl;

  return 0;
}
