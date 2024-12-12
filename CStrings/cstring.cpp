#include "cstring.h"
#include <cstring>
#include <iostream>

CString::CString() : str(nullptr)
{
  str = new char[1];
  *str = '\0';
}

CString::CString(const char *str) : str(nullptr)
{
  std::cout << "Executing CString(const char *str)" << std::endl;

  if (!str)
  {
    this->str = new char[1];
    *(this->str) = '\0'; // this->str[0] = '\0';
  }
  else
  {
    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str);
  }

}

CString::CString(const CString &source) : str(nullptr)
{
  std::cout << "Executing CString(const CString &source)" << std::endl;
  str = new char[strlen(source.getString()) + 1];
  strcpy(str, source.getString());
}

CString::~CString()
{
  delete [] str;
}

void CString::print() const
{
  std::cout << str << std::endl;
}

const char *CString::getString() const
{
  return str;
}
