#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

int main()
{
  std::string andrew {"Andrew 25 1.66"};
  std::istringstream input_str_stream {andrew};

  std::string name {};
  unsigned int age {};
  float height {};

  input_str_stream >> name >> age >> height;

  std::cout << "Name: " << name << std::endl;
  std::cout << "Age: " << age << std::endl;
  std::cout << "Height: " << height << std::endl;

  std::ostringstream output_str_stream {};

  output_str_stream << std::setw(10) << std::right << std::setfill('-')
                    << name
                    << std::setw(10) << age
                    << std::setw(10) << height;

  std::cout << output_str_stream.str() << std::endl;

  // Now, an example for validation purposes.

  std::cout << "== == ==" << std::endl;

  std::string user_input {};
  int number {};

  std::cout << "Write an integer: ";
  std::getline(std::cin, user_input);
  std::cout << "You wrote: " << user_input << std::endl;

  std::istringstream validation_stream {user_input};
  if(validation_stream >> number)
  {
    std::cout << "You effectively entered a number." << std::endl;
  }
  else
  {
    std::cout << "You didn't enter a number" << std::endl;
  }

  return 0;
}
