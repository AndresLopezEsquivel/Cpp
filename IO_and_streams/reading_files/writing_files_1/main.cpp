#include <iostream>
#include <fstream>
#include <string>

int main()
{
  std::string input_file_path {"./source.txt"};
  std::string output_file_path {"./copy.txt"};
  std::fstream input_file {input_file_path, std::ios::in};
  std::fstream output_file {output_file_path, std::ios::out};

  if(!input_file)
  {
    std::cerr << "Couldn't read input file." << std::endl;
    return 1;
  }

  if(!output_file)
  {
    std::cerr << "Couldn't read output file." << std::endl;
    return 1;
  }

  std::string line {};
  unsigned int n {1};

  while(std::getline(input_file, line))
  {
    output_file << n << " - " << line << std::endl;
    n++;
  }

  input_file.close();
  output_file.close();

  return 0;
}
