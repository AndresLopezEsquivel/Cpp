#include <iostream>
#include <fstream>

int main()
{
  std::ifstream file;
  file.open("./test.txt");

  if(!file) // If there was a problem opening the file
  {
    std::cerr << "File couldn't be opened." << std::endl;
    return 1;
  }

  std::string name;
  unsigned short age;
  float height;

  while(!file.eof())
  {
    // Insertion operator >> stops reading when it finds a space, a tab, or a newline.
    // We firstly read the name, then the age, and finally the height.
    file >> name >> age >> height;
    std::cout << std::left;
    std::cout << std::setw(10) << name;
    std::cout << std::setw(10) << age;
    std::cout << std::setw(10) << height;
    std::cout << std::endl;
  }

  file.close();

  return 0;
}
