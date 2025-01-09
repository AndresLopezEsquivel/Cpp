#include <iostream>
#include <fstream>

int main()
{
  std::fstream file {"./test.txt", std::ios::in};
  std::string line;
  int n {};

  if(!file)
  {
    std::cerr << "Couldn't open file." << std::endl;
    return 1;
  }

  std::cout << "By using std::getline" << std::endl;

  while(!file.eof())
  {
    std::getline(file, line);
    std::cout << line << std::endl;
    n++;
  }

  std::cout << "Iterations = " << n << std::endl;

  n = 0;
  char c;
  file.clear(); // clear eof and fail bits
  file.seekg(0, std::ios::beg); // move to the beginning of the file

  std::cout << std::endl << "By using file.get" << std::endl;

  while(file.get(c)) // get a character at the time from the file
  {
    std::cout << c;
    n++;
  }

  std::cout << "Iterations = " << n << std::endl;

  file.close();
  return 0;
}
