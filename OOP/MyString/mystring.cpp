#include <cstring>
#include <iostream>
#include "mystring.h"

MyString::MyString() : str(nullptr)
{
  std::cout << std::endl << "Inside MyString()" << std::endl;
  str = new char[1];
  *str = '\0';
}

MyString::MyString(const char *str) : str(nullptr)
{
  std::cout << std::endl << "Inside MyString(const char *str)" << std::endl;
  if(str == nullptr) {
    this->str = new char[1];
    *(this->str) = '\0';
    return;
  }

  size_t str_len = strlen(str);
  this->str = new char[str_len + 1]; // +1 to consider \0
  strcpy(this->str, str);
}

MyString::MyString(const MyString &source) : str(nullptr) // Copy constructor - Deep copy
{
  std::cout << std::endl << "Inside MyString(const MyString &source)" << std::endl;
  size_t str_len = strlen(source.str);
  str = new char[str_len + 1]; // +1 to conside \0
  strcpy(str, source.str);
}

MyString::~MyString() { delete [] str; }

char *MyString::get_str() const { return str; }
